// Fill out your copyright notice in the Description page of Project Settings.

#include "SetRequiredItemTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Gameplay/Items/BaseItem.h"

EBTNodeResult::Type USetRequiredItemTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		pBlackboard->SetValueAsClass(m_RequiredKey.SelectedKeyName, m_pItemClass);
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("SetRequiredItemTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}