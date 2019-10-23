// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "SickPerson1Pawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASickPerson1Pawn : public ANPCPawnBase
{
	GENERATED_BODY()
	
public:
	ASickPerson1Pawn();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};
