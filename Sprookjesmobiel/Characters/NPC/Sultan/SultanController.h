// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "SultanController.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASultanController : public ANPCControllerBase
{
	GENERATED_BODY()

public:
	ASultanController();

	//TESTING REMOVE WITH EVENT SYSTEM
	UFUNCTION(BlueprintCallable)
	void CurePrincess();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};