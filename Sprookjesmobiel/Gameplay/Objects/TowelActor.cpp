// Fill out your copyright notice in the Description page of Project Settings.

#include "TowelActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HintWidget.h"
#include "UI/InventoryWidget.h"

ATowelActor::ATowelActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATowelActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATowelActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();

	if (pInventory)
	{
		if (!pInventory->Contains(m_pReward))
		{
			//set hint
			ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
			hud->GetHintWidget()->SetNewHint("3",2);

			pInventory->AddItem(m_pReward);
			Destroy();
		}		
	}
}