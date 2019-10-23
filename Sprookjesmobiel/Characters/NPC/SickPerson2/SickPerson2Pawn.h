// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "SickPerson2Pawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASickPerson2Pawn : public ANPCPawnBase
{
	GENERATED_BODY()
	
public:
	ASickPerson2Pawn();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};
