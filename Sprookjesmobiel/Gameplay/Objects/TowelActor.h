// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "TowelActor.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ATowelActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ATowelActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};