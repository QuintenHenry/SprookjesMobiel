// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "SignActor.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	Left,
	Right
};

UCLASS()
class SPROOKJESMOBIEL_API ASignActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ASignActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Destination", Category = "Game Flow")
	FName m_Destination;

	UPROPERTY(EditAnywhere, DisplayName = "Fade Out", Category = "Game Flow")
	bool m_FadeOut;

	UPROPERTY(EditAnywhere, DisplayName = "Fade Time", Category = "Game Flow")
	float m_FadeTime;

	UPROPERTY(EditAnywhere, DisplayName = "Fade Time", Category = "Game Flow")
	EDirection m_Direction;

	FTimerHandle m_FadeHandle;
	void GoToDestination();
};