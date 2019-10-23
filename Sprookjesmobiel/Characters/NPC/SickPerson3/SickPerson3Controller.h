// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "SickPerson3Controller.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ASickPerson3Controller : public ANPCControllerBase
{
	GENERATED_BODY()

public:
	ASickPerson3Controller();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
	
};
