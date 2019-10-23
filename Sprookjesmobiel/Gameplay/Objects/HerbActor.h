// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "HerbActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class SPROOKJESMOBIEL_API AHerbActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:	
	AHerbActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};