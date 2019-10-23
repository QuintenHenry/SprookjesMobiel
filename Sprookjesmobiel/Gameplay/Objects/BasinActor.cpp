// Fill out your copyright notice in the Description page of Project Settings.

#include "BasinActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/HintWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/Items/BaseItem.h"

ABasinActor::ABasinActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABasinActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABasinActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	UBaseItem* pItem = pInventory->GetSelectedItem();

	if (!pItem)
		return;

	if (!pItem->IsA(m_pRequiredItem))
	{
		pInventory->ClearSelectedItem();
		//Play error sound
		UE_LOG(LogTemp, Warning, TEXT("BasinActor::Interact - Wrong selected item"));
		return;
	}

	//Towel
	if (pItem->IsA(m_pRequiredItem))
	{
		pInventory->RemoveItem(m_pRequiredItem);
		pInventory->AddItem(m_pReward);

		//set hint
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("4",2);
	}

	pInventory->ClearSelectedItem();
}