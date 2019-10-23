// Fill out your copyright notice in the Description page of Project Settings.

#include "IsNPCCuredDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UIsNPCCuredDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("IsNPCCuredDecorator::CalculateRawConditionValue - Could not get player from blackboard"));
			return false;
		}

		FGameInfo& gameInfo = pCharacter->GetGameInfo();

		switch (m_NPC)
		{
			case ESickNPC::EFirst:
				return gameInfo.IsSickPerson1Cured;

			case ESickNPC::ESecond:
				return gameInfo.IsSickPerson2Cured;

			case ESickNPC::EThird:
				return gameInfo.IsSickPerson3Cured;

			default:
				UE_LOG(LogTemp, Warning, TEXT("IsNPCCuredDecorator::CalculateRawConditionValue - Could not return NPC game state"));
				return false;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("IsNPCCuredDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}