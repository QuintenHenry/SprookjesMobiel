// Fill out your copyright notice in the Description page of Project Settings.

#include "SetNextQuestNPCTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USetNextQuestNPCTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		ANPCPawnBase* pSelf = Cast<ANPCPawnBase>(pBlackboard->GetValueAsObject(m_SelfKey.SelectedKeyName));
		if (!pSelf)
		{
			UE_LOG(LogTemp, Warning, TEXT("SetNextQuestNPCTask::ExecuteTask - Could not Self from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		ANPCPawnBase* pNext = GetNextNPC();
		pSelf->ShowQuestMarker(false);

		if (pNext)
			pNext->ShowQuestMarker(true);

		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("SetNextQuestNPCTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}

ANPCPawnBase* USetNextQuestNPCTask::GetNextNPC()
{
	if (m_pNextNPCClass)
	{
		TArray<AActor*> foundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), m_pNextNPCClass, foundActors);

		if (foundActors.Num() > 0)
		{
			if (foundActors.Num() > 1)
				UE_LOG(LogTemp, Warning, TEXT("SetNextQuestNPC::GetNextNPC - More than 1 NPC found with specified class, first one returned"));

			return Cast<ANPCPawnBase>(foundActors[0]);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("SetNextQuestNPC::GetNextNPC - Could not find NPC with specified class"));
			return nullptr;
		}
	}

	return nullptr;
}