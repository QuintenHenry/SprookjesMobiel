// Fill out your copyright notice in the Description page of Project Settings.

#include "CureNPCTask.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UCureNPCTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(pBlackboard->GetValueAsObject(m_PlayerKey.SelectedKeyName));
		if (!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("CureNPCTask::ExecuteTask - Could not get player from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		FGameInfo& gameInfo = pCharacter->GetGameInfo();

		switch (m_NPC)
		{
			case ESickNPC::EFirst:
				gameInfo.IsSickPerson1Cured = true;
				return EBTNodeResult::Type::Succeeded;

			case ESickNPC::ESecond:
				gameInfo.IsSickPerson2Cured = true;
				return EBTNodeResult::Type::Succeeded;

			case ESickNPC::EThird:
				gameInfo.IsSickPerson3Cured = true;
				return EBTNodeResult::Type::Succeeded;

			default:
				UE_LOG(LogTemp, Warning, TEXT("CureNPCTask::ExecuteTask - Could not return NPC game state"));
				return EBTNodeResult::Type::Failed;
		}	
	}

	UE_LOG(LogTemp, Warning, TEXT("CureNPCTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}