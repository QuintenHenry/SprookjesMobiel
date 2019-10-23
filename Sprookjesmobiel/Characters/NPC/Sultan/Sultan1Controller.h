// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "Sultan1Controller.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASultan1Controller : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	ASultan1Controller();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};