// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "LailaCairoPawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ALailaCairoPawn : public ANPCPawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALailaCairoPawn();

	virtual void Interact(APlayerCharacter* pPlayer) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
