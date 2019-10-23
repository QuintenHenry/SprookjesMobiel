// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "AnswerDecorator.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API UAnswerDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Answer Key", Category = "Input")
	FBlackboardKeySelector m_AnswerKey;

	UPROPERTY(EditAnywhere, DisplayName = "Is Answer", Category = "Input")
	EAnswer m_Answer;
};
