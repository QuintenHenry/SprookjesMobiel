// Fill out your copyright notice in the Description page of Project Settings.

#include "IsRequiredItemEmptyDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UIsRequiredItemEmptyDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		UClass* pRequiredObject = pBlackboard->GetValueAsClass(m_RequiredKey.SelectedKeyName);
		return (pRequiredObject == nullptr);
	}

	UE_LOG(LogTemp, Warning, TEXT("IsRequiredItemEmptyDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}