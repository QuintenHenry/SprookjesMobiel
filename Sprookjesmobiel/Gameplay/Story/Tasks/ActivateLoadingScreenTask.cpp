// Fill out your copyright notice in the Description page of Project Settings.

#include "ActivateLoadingScreenTask.h"
#include "UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UActivateLoadingScreenTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));
		if (!pHUD)
		{
			UE_LOG(LogTemp, Warning, TEXT("ActivateLoadingScreenTask::ExecuteTask - Could not get HUD from blackboard"));
			return EBTNodeResult::Type::Failed;
		}

		pHUD->ActivateLoadingScreen();
		return EBTNodeResult::Type::Succeeded;
	}

	UE_LOG(LogTemp, Warning, TEXT("ActivateLoadingScreenTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}