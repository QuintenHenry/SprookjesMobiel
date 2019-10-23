// Fill out your copyright notice in the Description page of Project Settings.

#include "CoffeePotActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/HintWidget.h"
#include "Gameplay/Items/BaseItem.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

ACoffeePotActor::ACoffeePotActor()
{
	PrimaryActorTick.bCanEverTick = false;

	m_HasAddedLeaves = false;
}

void ACoffeePotActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACoffeePotActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	UBaseItem* pItem = pInventory->GetSelectedItem();

	pInventory->ClearSelectedItem();

	if (!pItem)
		return;

	if (!pItem->IsA(m_pRequiredItem) && !pItem->IsA(m_pLeavesClass))
	{
		pInventory->ClearSelectedItem();
		//Play error sound
		UE_LOG(LogTemp, Warning, TEXT("BasinActor::Interact - Wrong selected item"));
		return;
	}

	//Leaves
	if (pItem->IsA(m_pLeavesClass))
	{
		pInventory->RemoveItem(m_pLeavesClass);
		m_HasAddedLeaves = true;
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("6",5);

	}

	//Mug
	if (pItem->IsA(m_pRequiredItem) && m_HasAddedLeaves)
	{
		pInventory->RemoveItem(m_pRequiredItem);
		pInventory->AddItem(m_pReward);
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("8",5);
	}
}

void ACoffeePotActor::Delete()
{
	APlayerCharacter* pPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	pInventory->AddItem(m_pReward);
}