// Fill out your copyright notice in the Description page of Project Settings.

#include "ClearActiveNPCTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/Player/PlayerCharacter.h"

EBTNodeResult::Type UClearActiveNPCTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("ClearActiveNPCTask::ExecuteTask - Could not get player from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		pCharacter->SetActiveNPC(nullptr);
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("ClearActiveNPCTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}