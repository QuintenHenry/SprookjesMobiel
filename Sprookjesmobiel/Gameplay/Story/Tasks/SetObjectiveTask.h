// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Characters/Player/PlayerCharacter.h"
#include "SetObjectiveTask.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API USetObjectiveTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Player Key", Category = "Input")
	FBlackboardKeySelector m_PlayerKey;

	UPROPERTY(EditAnywhere, DisplayName = "New Objective", Category = "Input")
	EObjective m_NewObjective;
};