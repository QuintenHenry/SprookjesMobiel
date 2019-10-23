// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "LutePersonController.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ALutePersonController : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	ALutePersonController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};
