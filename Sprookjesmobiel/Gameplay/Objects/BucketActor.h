// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "BucketActor.generated.h"

class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API ABucketActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	ABucketActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;
};
