// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetHintTask.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API USetHintTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Hint", Category = "Input")
	FString m_Hint;
	UPROPERTY(EditAnywhere, DisplayName = "Skippable Hint Index", Category = "Input")
	int32 m_SkippableHints = -1;
};
