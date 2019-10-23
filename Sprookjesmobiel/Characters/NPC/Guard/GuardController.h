// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "GuardController.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AGuardController : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	AGuardController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};