// Fill out your copyright notice in the Description page of Project Settings.

#include "ShowAnswersTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"

UShowAnswersTask::UShowAnswersTask()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UShowAnswersTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	m_pBlackboard = OwnerComp.GetBlackboardComponent();

	if (m_pBlackboard)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(m_pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));
		if (pHUD)
		{
			UDialogueWidget* pWidget = pHUD->GetDialogueWidget();
			pWidget->SetAnswers(m_TopAnswer, m_MiddleAnswer, m_BottomAnswer);

			return BindAnswerEvent(OwnerComp, pWidget);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ShowAnswersTask::ExecuteTask - Could not get HUD from blackboard"));
			return EBTNodeResult::Type::Failed;
		}	
	}

	UE_LOG(LogTemp, Warning, TEXT("ShowAnswersTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}

EBTNodeResult::Type UShowAnswersTask::BindAnswerEvent(UBehaviorTreeComponent& OwnerComp, UDialogueWidget* pWidget)
{
	pWidget->GetAnswerDispatcher().AddDynamic(this, &UShowAnswersTask::SetAnswer);
	FinishLatentTask(OwnerComp, EBTNodeResult::Type::InProgress);
	return EBTNodeResult::Type::InProgress;
}

void UShowAnswersTask::SetAnswer(EAnswer answer)
{
	UE_LOG(LogTemp, Warning, TEXT("Answer received!"));

	//Set answer
	m_pBlackboard->SetValueAsEnum(m_AnswerKey.SelectedKeyName, static_cast<uint8>(answer));

	//Clear answers
	ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(m_pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));
	UDialogueWidget* pWidget = pHUD->GetDialogueWidget();
	pWidget->SetAnswers(FString(), FString(), FString());

	//Unbind
	pWidget->GetAnswerDispatcher().RemoveDynamic(this, &UShowAnswersTask::SetAnswer);

	UBehaviorTreeComponent* pOwnerComp = Cast<UBehaviorTreeComponent>(GetOuter());
	if (pOwnerComp)
		FinishLatentTask(*pOwnerComp, EBTNodeResult::Type::Succeeded);
}