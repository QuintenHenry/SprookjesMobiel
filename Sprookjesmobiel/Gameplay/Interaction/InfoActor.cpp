// Fill out your copyright notice in the Description page of Project Settings.

#include "InfoActor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Characters/Player/PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Characters/Player/MainPlayerController.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"
#include "UI/InfoObjectsWidget.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AInfoActor::AInfoActor()
{
	//Init components
	m_pSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	m_pSpringArmComponent->SetupAttachment(RootComponent);

	m_pCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	m_pCameraComponent->SetupAttachment(m_pSpringArmComponent);

	//Set defaults
	PrimaryActorTick.bCanEverTick = true;
	m_InfoMessages.SetNumUninitialized(0);
	m_RotateCamera = true;
	m_CamRotateMultiplier = 1.0f;
	m_InfoCounter = -1;
}

void AInfoActor::BeginPlay()
{
	Super::BeginPlay();

	m_CamStartRotation = m_pSpringArmComponent->GetComponentRotation();
}

void AInfoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_RotateCamera)
	{
		APlayerController* pController = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		if (pController)
		{
			if (pController->GetViewTarget() == this)
			{
				FRotator rotation = FRotator(0.0f, 20.0f * DeltaTime, 0.0f);
				m_pSpringArmComponent->AddWorldRotation(rotation * m_CamRotateMultiplier);
			}
			else
				m_pSpringArmComponent->SetWorldRotation(m_CamStartRotation);
		}
	}
}

void AInfoActor::Interact(APlayerCharacter* pPlayer)
{
	//pPlayer->Find(this);


	//Change camera
	APlayerController* pController = Cast<APlayerController>(pPlayer->GetController());

	pPlayer->SetInfoActor(this);
	pPlayer->SetActorHiddenInGame(true);
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(pController, pPlayer->GetActorLocation());

	ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(pController->GetHUD());
	if (pController)
	{
		pController->SetViewTargetWithBlend(this, 1.0f);
		UDialogueWidget* pDialogueWidget = pHUD->GetDialogueWidget();

		pDialogueWidget->Open();
		pDialogueWidget->SetPhrase(GetInfo(), EActiveDialogueSide::ENone);
		pDialogueWidget->SetLeftSprite(nullptr);
		pDialogueWidget->SetRightSprite(nullptr);
		pDialogueWidget->SetLeftName(FString());
		pDialogueWidget->SetRightName(FString());
	}


	if (m_Collected)
		return;
	UInfoObjectsWidget *pInfoObject = pHUD->GetInfoWidget();
	pInfoObject->Update();
	pInfoObject->Show();	
	m_Collected = true;


}

FString AInfoActor::GetInfo()
{
	++m_InfoCounter;

	if (m_InfoCounter < m_InfoMessages.Num() && m_InfoCounter > -1)
		return m_InfoMessages[m_InfoCounter];

	m_InfoCounter = -1;
	return FString();
}