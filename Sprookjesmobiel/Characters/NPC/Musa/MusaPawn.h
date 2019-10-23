// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "MusaPawn.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API AMusaPawn : public ANPCPawnBase
{
	GENERATED_BODY()

public:
	AMusaPawn();

protected:
	virtual void BeginPlay() override;
	
};
