// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "GuardPawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AGuardPawn : public ANPCPawnBase
{
	GENERATED_BODY()
	
public:
	AGuardPawn();

	UFUNCTION(BlueprintCallable)
	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};