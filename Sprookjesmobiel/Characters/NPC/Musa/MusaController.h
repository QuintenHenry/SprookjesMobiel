// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "MusaController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API AMusaController : public ANPCControllerBase
{
	GENERATED_BODY()

public:
	AMusaController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
	
};
