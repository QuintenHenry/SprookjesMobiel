// Fill out your copyright notice in the Description page of Project Settings.

#include "SetPhraseTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UI/SprookjesmobielHUD.h"
#include "GameFramework/Character.h"
#include "Characters/Player/MainPlayerController.h"
#include "SprookjesmobielGameModeBase.h"
#include "Kismet/GameplayStatics.h"

USetPhraseTask::USetPhraseTask()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type USetPhraseTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	m_pBlackboard = OwnerComp.GetBlackboardComponent();

	if (m_pBlackboard)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(m_pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));
		if (pHUD)
		{
			UDialogueWidget* pWidget = pHUD->GetDialogueWidget();
			pWidget->SetPhrase(m_Phrase, m_ActiveSide);

			return (m_WaitForInput) ? BindInputEvent(OwnerComp) : EBTNodeResult::Type::Succeeded;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("SetPhraseTask::ExecuteTask - Could not get HUD from blackboard"));
			return EBTNodeResult::Type::Failed;
		}	
	}

	UE_LOG(LogTemp, Warning, TEXT("SetPhraseTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}

EBTNodeResult::Type USetPhraseTask::BindInputEvent(UBehaviorTreeComponent& OwnerComp)
{
	ACharacter* pCharacter = Cast<ACharacter>(m_pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	if (pCharacter)
	{
		AMainPlayerController* pController = Cast<AMainPlayerController>(pCharacter->GetController());

		if (pGameMode->InDevMode())
			pController->GetInputDispatcher().AddDynamic(this, &USetPhraseTask::ContinueWithSkip);
		else
			pController->GetInputDispatcher().AddDynamic(this, &USetPhraseTask::Continue);

		FinishLatentTask(OwnerComp, EBTNodeResult::Type::InProgress);
		return EBTNodeResult::Type::InProgress;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SetPhraseTask::BindInputEvent - Could not get character from blackboard"));
		return EBTNodeResult::Type::Failed;
	}		
}

void USetPhraseTask::Continue()
{
	UE_LOG(LogTemp, Warning, TEXT("Input event received!"));

	ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(m_pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));
	UDialogueWidget* pWidget = pHUD->GetDialogueWidget();

	if (!pWidget->IsTypingText())
	{
		ACharacter* pCharacter = Cast<ACharacter>(m_pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		AMainPlayerController* pController = Cast<AMainPlayerController>(pCharacter->GetController());
		pController->GetInputDispatcher().RemoveDynamic(this, &USetPhraseTask::Continue);

		UBehaviorTreeComponent* pOwnerComp = Cast<UBehaviorTreeComponent>(GetOuter());
		if (pOwnerComp)
			FinishLatentTask(*pOwnerComp, EBTNodeResult::Type::Succeeded);
	}
}

//Dev testing, allows us to skip through dialogues
void USetPhraseTask::ContinueWithSkip()
{
	ACharacter* pCharacter = Cast<ACharacter>(m_pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
	AMainPlayerController* pController = Cast<AMainPlayerController>(pCharacter->GetController());
	pController->GetInputDispatcher().RemoveDynamic(this, &USetPhraseTask::ContinueWithSkip);

	UBehaviorTreeComponent* pOwnerComp = Cast<UBehaviorTreeComponent>(GetOuter());
	if (pOwnerComp)
		FinishLatentTask(*pOwnerComp, EBTNodeResult::Type::Succeeded);
}