// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDialogueTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"

EBTNodeResult::Type UOpenDialogueTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(pBlackboard->GetValueAsObject(m_HUDKey.SelectedKeyName));

		if (pHUD)
		{
			UDialogueWidget* pWidget = pHUD->GetDialogueWidget();
			pWidget->Open();
			return EBTNodeResult::Type::Succeeded;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("OpenDialogueTask::ExecuteTask - Could not get HUD from blackboard"));
			return EBTNodeResult::Type::Failed;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("OpenDialogueTask::ExecuteTask - Could not get blackboard component"));
	return EBTNodeResult::Type::Failed;
}