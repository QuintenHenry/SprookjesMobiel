// Fill out your copyright notice in the Description page of Project Settings.

#include "GivesRequiredItemDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"

bool UGivesRequiredItemDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		UClass* pRequiredObject = pBlackboard->GetValueAsClass(m_RequiredKey.SelectedKeyName);
		
		//Check for errors
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("GivesRequiredItemDecorator::CalculateRawConditionValue - Could not get player from blackboard"));
			return false;
		}
		if (!pRequiredObject)
		{
			UE_LOG(LogTemp, Warning, TEXT("GivesRequiredItemDecorator::CalculateRawConditionValue - Could not get required object from blackboard"));
			return false;
		}

		//Perform check
		UInventoryWidget* pInventory = pCharacter->GetInventory();
		UBaseItem* pItem = pInventory->GetSelectedItem();

		if (!pItem)
			return false;

		return (pItem->IsA(pRequiredObject));
	}

	UE_LOG(LogTemp, Warning, TEXT("GivesRequiredItemDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}