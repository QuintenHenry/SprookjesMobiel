// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectiveDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UObjectiveDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("ObjectiveDecorator::CalculateRawConditionValue - Could not get player from blackboard"));
			return false;
		}

		FGameInfo& gameInfo = pCharacter->GetGameInfo();
		return (gameInfo.Objective == m_Objective);
	}

	UE_LOG(LogTemp, Warning, TEXT("ObjectiveDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}