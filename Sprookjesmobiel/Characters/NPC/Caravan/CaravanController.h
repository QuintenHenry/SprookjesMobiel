// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "CaravanController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ACaravanController : public ANPCControllerBase
{
	GENERATED_BODY()
	ACaravanController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
	
};
