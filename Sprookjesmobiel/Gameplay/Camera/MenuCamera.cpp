// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuCamera.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMenuCamera::AMenuCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMenuCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	pController->bShowMouseCursor = true;

	FInputModeUIOnly inputmode;


	pController->SetInputMode(inputmode);

	//add menu widget
	//CreateWidget<UMenuWidget>(pController)->AddToViewport();;

	m_CurrentTransform = m_MainCameraTransform;
	
	
}

void AMenuCamera::SetCameraTarget(CurrentMenu menu)
{
	switch (menu)
	{
	case AMenuCamera::Main:
		m_CurrentTransform = m_MainCameraTransform;
		break;
	case AMenuCamera::Options:
		m_CurrentTransform = m_OptionsCameraTransform;
		break;
	case AMenuCamera::Help:
		m_CurrentTransform = m_HelpCameraTransform;
		break;
	}
}

// Called every frame
void AMenuCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LerpedPos = FMath::Lerp(GetActorLocation(), m_CurrentTransform->GetActorLocation(), DeltaTime*m_Speed);
	SetActorLocation(LerpedPos);
}

// Called to bind functionality to input
void AMenuCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

