// Fill out your copyright notice in the Description page of Project Settings.

#include "SetBlackboardFlagTask.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetBlackboardFlagTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		pBlackboard->SetValueAsBool(m_FlagKey.SelectedKeyName, m_Value);
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("SetBlackboardFlagTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}