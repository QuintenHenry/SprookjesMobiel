// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "Characters/Player/MainPlayerController.h"
#include "Gameplay/Camera/MainCameraActor.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "Kismet/GameplayStatics.h"
#include "UI/InventoryWidget.h"
#include "Engine/World.h"
#include "Gameplay/Items/BaseItem.h"
#include "SprookjesmobielGameModeBase.h"
#include "Managers/SoundManager.h"
#include "Gameplay/Interaction/InfoObjectsComponent.h"
#include "Gameplay/Interaction/InfoActor.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//Initialize components
	m_pBlindfoldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlindfoldMesh"));
	m_pBlindfoldMesh->SetupAttachment(GetMesh());

	m_pInfoComponent = CreateDefaultSubobject<UInfoObjectsComponent>(TEXT("InfoComponent"));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Initialize camera
	if(!m_CameraToSpawn) 
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter::BeginPlay - Camera Class not set!"));
		return;
	}

	AMainPlayerController* pController = Cast<AMainPlayerController>(GetController());
	if(pController)
	{
		AMainCameraActor* pCamera = GetWorld()->SpawnActor<AMainCameraActor>(m_CameraToSpawn);
		pController->SetViewTargetWithBlend(pCamera);
		m_pCamera = pCamera;
	}

	//Set objective
	m_GameInfo.Objective = EObjective::EGoToFirstPerson;
}

void APlayerCharacter::InteractWithSelf()
{
	UBaseItem* pItem = m_pInventory->GetSelectedItem();

	if (pItem)
	{
		if (pItem->IsA(m_pLeavesClass))
		{
			UE_LOG(LogTemp, Warning, TEXT("Using Magic Leaves to heal..."));
			m_pInventory->ClearSelectedItem();

			ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			ASoundManager* pSoundManager = pGameMode->GetSoundManager();

			if (pSoundManager)
				pSoundManager->PlaySound("Success");

			m_GameInfo.IsMuhsinCured = true;
			m_pBlindfoldMesh->SetHiddenInGame(true);

			UCapsuleComponent* pCapsule = Cast<UCapsuleComponent>(RootComponent);
			pCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Ignore);
		}
	}
}

void APlayerCharacter::SetInfoActor(AInfoActor* pInfoObject)
{
	m_pActiveInfoObject = pInfoObject;
	m_pActiveDialogueNPC = nullptr;
}

void APlayerCharacter::SetCamera(AMainCameraActor* pCamera)
{
	m_pCamera = pCamera;
}

void APlayerCharacter::SetInventory(UInventoryWidget* pInventory)
{
	m_pInventory = pInventory;
}

void APlayerCharacter::SetInteractable(AActor* pInteractable)
{
	m_pCurrentInteractable = pInteractable;

	if (!pInteractable)
		return;

	//Check if actor
	AInteractableActor* pActor = Cast<AInteractableActor>(pInteractable);
	if (pActor)
	{
		
		if (pActor->IsOverlappingActor(this))
		{
			m_pCurrentInteractable = nullptr;
			pActor->Interact(this);
		}
		return;
	}
	

	//Check if NPC
	ANPCPawnBase* pNPC = Cast<ANPCPawnBase>(pInteractable);
	if (pNPC)
	{
		if (pNPC->IsOverlappingActor(this))
		{
			m_pCurrentInteractable = nullptr;
			pNPC->Interact(this);
		}
		return;
	}
	return;
}

void APlayerCharacter::SetActiveNPC(ANPCPawnBase* pNPC)
{
	m_pActiveDialogueNPC = pNPC;
}