// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "CoffeePotActor.generated.h"

class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API ACoffeePotActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ACoffeePotActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Leaves Class", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pLeavesClass;

	bool m_HasAddedLeaves;

	void Delete();
};