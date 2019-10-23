// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "PrincessController.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API APrincessController : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	APrincessController();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};