// Fill out your copyright notice in the Description page of Project Settings.

#include "SetHintTask.h"
#include "Sprookjesmobiel/UI/HintWidget.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USetHintTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());	
	
		hud->GetHintWidget()->SetNewHint(m_Hint, m_SkippableHints);

		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("CureNPCTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}