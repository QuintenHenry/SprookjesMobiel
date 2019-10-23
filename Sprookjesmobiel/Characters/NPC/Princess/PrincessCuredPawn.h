// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "PrincessCuredPawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API APrincessCuredPawn : public ANPCPawnBase
{
	GENERATED_BODY()
	
public:
	APrincessCuredPawn();

protected:
	virtual void BeginPlay() override;
};
