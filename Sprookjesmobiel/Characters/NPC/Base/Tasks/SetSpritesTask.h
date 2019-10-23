// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetSpritesTask.generated.h"

class UTexture2D;

UCLASS()
class SPROOKJESMOBIEL_API USetSpritesTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "HUD Key", Category = "Input")
	FBlackboardKeySelector m_HUDKey;

	UPROPERTY(EditAnywhere, DisplayName = "Left Sprite", Category = "Input")
	UTexture2D* m_pLeftSprite;

	UPROPERTY(EditAnywhere, DisplayName = "Right Sprite", Category = "Input")
	UTexture2D* m_pRightSprite;
};
