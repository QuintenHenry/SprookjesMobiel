// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MenuCamera.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AMenuCamera : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMenuCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	enum CurrentMenu
	{
		Main,Options,Help
	};
	void SetCameraTarget(CurrentMenu menu);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Main Camera Transform", Category = "Default", Meta = (AllowPrivateAccess = "true"))
	AActor *m_MainCameraTransform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Options Camera Transform", Category = "Default", Meta = (AllowPrivateAccess = "true"))
	AActor *m_OptionsCameraTransform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Help Camera Transform", Category = "Default", Meta = (AllowPrivateAccess = "true"))
	AActor *m_HelpCameraTransform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Camera Move Speed", Category = "Default", Meta = (AllowPrivateAccess = "true"))
	float m_Speed;



	AActor *m_CurrentTransform;
};
