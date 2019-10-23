// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "SickPerson2Controller.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASickPerson2Controller : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	ASickPerson2Controller();

protected:
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;
};