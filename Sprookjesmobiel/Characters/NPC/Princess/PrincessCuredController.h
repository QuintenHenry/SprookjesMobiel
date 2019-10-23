// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "PrincessCuredController.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API APrincessCuredController : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	APrincessCuredController();

	UFUNCTION(BlueprintCallable)
	void EnableMarriage();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};
