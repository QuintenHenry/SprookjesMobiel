// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Components/ArrowComponent.h"
#include "Animation/AnimInstance.h"
#include "ThroneActor.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AThroneActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThroneActor();
	virtual void Interact(APlayerCharacter* pPlayer) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Components")
	UArrowComponent* m_pStartTarget;
	APlayerCharacter* m_pPlayerCharacter;
	UAnimInstance* m_pAnimationInstance;

	bool m_PlayerSitting{};
};
