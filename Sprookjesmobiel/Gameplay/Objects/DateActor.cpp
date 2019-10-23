// Fill out your copyright notice in the Description page of Project Settings.

#include "DateActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"
#include "Sprookjesmobiel/UI/HintWidget.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

ADateActor::ADateActor()
{
	//Constructor
}

void ADateActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADateActor::Interact(APlayerCharacter* pPlayer)
{
	if(GotDates)
		return;

	if(pPlayer->GetGameInfo().Objective != EObjective::ECureSecondPerson)
		return;

	//Set Hint
	ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	hud->GetHintWidget()->SetNewHint("6",5);

	if (!m_pDateItem || !m_pDateItem2 || !m_pDateItem3)
	{
		UE_LOG(LogTemp, Warning, TEXT("DateActor::Interact - Inventory class is empty"));
		return;
	}

	//Check for selected item
	UInventoryWidget* pInventory = pPlayer->GetInventory();

	if (pInventory->GetSelectedItem())
	{
		UE_LOG(LogTemp, Warning, TEXT("I can't do that."));
		pInventory->ClearSelectedItem();
		return;
	}

	//Get date
	if(!pInventory->Contains(m_pDateItem) &&
	   !pInventory->Contains(m_pDateItem2) &&
	   !pInventory->Contains(m_pDateItem3))
	{
		pInventory->AddItem(m_pDateItem);
		Disable();
	}
	else if (pInventory->Contains(m_pDateItem))
	{
		pInventory->RemoveItem(m_pDateItem);
		pInventory->AddItem(m_pDateItem2);
		Disable();
	}
	else if (pInventory->Contains(m_pDateItem2))
	{
		pInventory->RemoveItem(m_pDateItem2);
		pInventory->AddItem(m_pDateItem3);
		Disable();
	}
	/*else if (!pInventory->Contains(m_pDateItem3))
	{
		pInventory->AddItem(m_pDateItem);
		Disable();
		GotDates = true;
	}*/
	UE_LOG(LogTemp, Warning, TEXT("I don't need more dates"));
}

void ADateActor::Disable()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	SetActorEnableCollision(false);
	m_pStaticMeshComp->SetSimulatePhysics(false);
}

void ADateActor::Enable()
{
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	SetActorEnableCollision(true);
	m_pStaticMeshComp->SetSimulatePhysics(true);
}