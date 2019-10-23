// Fill out your copyright notice in the Description page of Project Settings.

#include "TakeItemTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"

EBTNodeResult::Type UTakeItemTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("TakeItemTask::ExecuteTask - Could not get player from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		UInventoryWidget* pInventory = pCharacter->GetInventory();
		pInventory->RemoveItem(m_ItemClass);
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("TakeItemTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}