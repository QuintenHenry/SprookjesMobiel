// Fill out your copyright notice in the Description page of Project Settings.

#include "MugActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/HintWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"

AMugActor::AMugActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMugActor::BeginPlay()
{
	Super::BeginPlay();
}

void AMugActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();

	if (pInventory)
	{

		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("7",5);
		pInventory->AddItem(m_pReward);
		Destroy();
	}
}