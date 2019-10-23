// Fill out your copyright notice in the Description page of Project Settings.

#include "SignActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Characters/Player/MainPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/InventoryWidget.h"

ASignActor::ASignActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASignActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASignActor::Interact(APlayerCharacter* pPlayer)
{
	if (m_FadeOut)
	{
		APlayerCameraManager* pCamManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
		pCamManager->StartCameraFade(0.0f, 1.0f, m_FadeTime, FLinearColor::Black, true, true);

		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if(!pCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find character"));
			return;
		}

		UInventoryWidget* pInventory = pCharacter->GetInventory();
		if(!pInventory)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find inventory"));
			return;
		}
		
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->FadeOut(m_FadeTime);

		pInventory->FadeOut(m_FadeTime);

		GetWorldTimerManager().SetTimer(m_FadeHandle, this, &ASignActor::GoToDestination, m_FadeTime, false);

		APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		FVector offset;
		if(m_Direction == EDirection::Left)
			offset = FVector(0,-1000.0f,0);
		else if(m_Direction == EDirection::Right)
			offset = FVector(0,1000.0f,0);

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(pController, GetActorLocation() + offset);
	}
	else
		GoToDestination();
}

void ASignActor::GoToDestination()
{
	UGameplayStatics::OpenLevel(GetWorld(), m_Destination);
}