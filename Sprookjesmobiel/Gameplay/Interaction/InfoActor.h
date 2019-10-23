// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "Math/Rotator.h"
#include "InfoActor.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SPROOKJESMOBIEL_API AInfoActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AInfoActor();

	virtual void Tick(float DeltaTime) override;
	virtual void Interact(APlayerCharacter* pPlayer) override;
	
	FString GetInfo();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, DisplayName = "Spring Arm Component", Category = "Components")
	USpringArmComponent* m_pSpringArmComponent;

	UPROPERTY(VisibleAnywhere, DisplayName = "Camera Component", Category = "Components")
	UCameraComponent* m_pCameraComponent;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Info", Category = "Information")
	TArray<FString> m_InfoMessages;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Rotate Camera", Category = "Information")
	bool m_RotateCamera;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Cam Rotate Multiplier", Category = "Information")
	float m_CamRotateMultiplier;

	FRotator m_CamStartRotation;
	int32 m_InfoCounter;

	bool m_Collected = false;
};