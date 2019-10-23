// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "DeliveryPersonController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ADeliveryPersonController : public ANPCControllerBase
{
	GENERATED_BODY()
public:
	ADeliveryPersonController();
		
protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};
