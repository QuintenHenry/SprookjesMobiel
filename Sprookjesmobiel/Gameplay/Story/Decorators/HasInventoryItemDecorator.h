// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "HasInventoryItemDecorator.generated.h"

class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API UHasInventoryItemDecorator : public UBTDecorator
{
	GENERATED_BODY()
	
protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Player Key", Category = "Input")
	FBlackboardKeySelector m_PlayerKey;

	UPROPERTY(EditAnywhere, DisplayName = "Item Class", Category = "Input")
	TSubclassOf<UBaseItem> m_pItemClass;

	UPROPERTY(EditAnywhere, DisplayName = "Quantity", Category = "Input")
	int m_Quantity=1;
};