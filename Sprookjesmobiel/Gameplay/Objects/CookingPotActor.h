// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "CookingPotActor.generated.h"

class UParticleSystemComponent;
class UAudioComponent;

UCLASS()
class SPROOKJESMOBIEL_API ACookingPotActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ACookingPotActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, DisplayName = "Fire Particle", Category = "Components")
	UParticleSystemComponent* m_pFireComponent;

	UPROPERTY(VisibleAnywhere, DisplayName = "Fire Audio", Category = "Components")
	UAudioComponent* m_pAudioComponent;

	UPROPERTY(EditAnywhere, DisplayName = "Extra Required Item", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pExtraRequired;

	bool m_IsFireOn;
};