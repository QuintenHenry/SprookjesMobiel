// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetNamesTask.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API USetNamesTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "HUD Key", Category = "Input")
	FBlackboardKeySelector m_HUDKey;

	UPROPERTY(EditAnywhere, DisplayName = "Left Name", Category = "Input")
	FString m_LeftName;

	UPROPERTY(EditAnywhere, DisplayName = "Right Name", Category = "Input")
	FString m_RightName;
};
