// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetRequiredItemTask.generated.h"

class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API USetRequiredItemTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Required Object Key", Category = "Input")
	FBlackboardKeySelector m_RequiredKey;

	UPROPERTY(EditAnywhere, DisplayName = "Item Class", Category = "Input")
	TSubclassOf<UBaseItem> m_pItemClass;
};
