// Fill out your copyright notice in the Description page of Project Settings.

#include "SetObjectiveTask.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetObjectiveTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) 
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("SetObjectiveTask::ExecuteTask - Could not get Player from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		FGameInfo& gameInfo = pCharacter->GetGameInfo();
		gameInfo.Objective = m_NewObjective;
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("SetObjectiveTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}