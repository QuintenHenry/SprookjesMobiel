// Fill out your copyright notice in the Description page of Project Settings.

#include "IsSelectedItemEmptyDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"

bool UIsSelectedItemEmptyDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("IsSelectedItemEmptyDecorator::CalculateRawConditionValue - Could not get player from blackboard"));
			return false;
		}

		UInventoryWidget* pInventory = pCharacter->GetInventory();
		return (pInventory->GetSelectedItem() == nullptr);
	}

	UE_LOG(LogTemp, Warning, TEXT("IsSelectedItemEmptyDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}