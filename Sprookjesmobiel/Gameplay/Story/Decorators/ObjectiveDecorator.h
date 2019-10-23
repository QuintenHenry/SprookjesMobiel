// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Characters/Player/PlayerCharacter.h"
#include "ObjectiveDecorator.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API UObjectiveDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Player Key", Category = "Input")
	FBlackboardKeySelector m_PlayerKey;

	UPROPERTY(EditAnywhere, DisplayName = "Objective", Category = "Input")
	EObjective m_Objective;
};