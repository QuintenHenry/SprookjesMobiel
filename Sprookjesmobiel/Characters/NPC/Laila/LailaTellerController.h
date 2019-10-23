// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "LailaTellerController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ALailaTellerController : public ANPCControllerBase
{
	GENERATED_BODY()
public:
	ALailaTellerController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};
