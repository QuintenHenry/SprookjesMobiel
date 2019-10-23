// Fill out your copyright notice in the Description page of Project Settings.

#include "IsNPCTalkingDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "Characters/Player/PlayerCharacter.h"

bool UIsNPCTalkingDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		ANPCPawnBase* pSelf = Cast<ANPCPawnBase>(pBlackboard->GetValueAsObject(m_SelfKey.SelectedKeyName));
		if (!pSelf)
		{
			UE_LOG(LogTemp, Warning, TEXT("IsNPCTalkingDecorator::CalculateRawConditionValue - Could not get Self from blackboard"));
			return false;
		}

		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("IsNPCTalkingDecorator::CalculateRawConditionValue - Could not get player from blackboard"));
			return false;
		}
		
		return (pCharacter->GetActiveNPC() == pSelf);
	}

	UE_LOG(LogTemp, Warning, TEXT("IsNPCTalkingDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}