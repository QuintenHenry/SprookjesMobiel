// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "IsRequiredItemEmptyDecorator.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API UIsRequiredItemEmptyDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Required Object Key", Category = "Input")
	FBlackboardKeySelector m_RequiredKey;
};