// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "PestlePersonController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API APestlePersonController : public ANPCControllerBase
{
	GENERATED_BODY()

public:
	APestlePersonController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};
