// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "MugActor.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AMugActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AMugActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};