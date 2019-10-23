// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "IsNPCTalkingDecorator.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API UIsNPCTalkingDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Self Key", Category = "Input")
	FBlackboardKeySelector m_SelfKey;

	UPROPERTY(EditAnywhere, DisplayName = "Player Key", Category = "Input")
	FBlackboardKeySelector m_PlayerKey;
};
