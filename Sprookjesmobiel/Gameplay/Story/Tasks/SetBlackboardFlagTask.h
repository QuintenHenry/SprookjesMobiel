// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetBlackboardFlagTask.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API USetBlackboardFlagTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Flag Key", Category = "Input")
	FBlackboardKeySelector m_FlagKey;

	UPROPERTY(EditAnywhere, DisplayName = "Value", Category = "Input")
	bool m_Value;
};
