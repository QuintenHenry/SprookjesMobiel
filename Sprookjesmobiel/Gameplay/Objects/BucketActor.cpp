// Fill out your copyright notice in the Description page of Project Settings.

#include "BucketActor.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Player/PlayerCharacter.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"
#include "Sprookjesmobiel/UI/HintWidget.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"


ABucketActor::ABucketActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABucketActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABucketActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	UBaseItem* pItem = pInventory->GetSelectedItem();

	if (!pItem && pPlayer->GetGameInfo().Objective == EObjective::ECureThirdPerson /*&& pInventory->Contains(m_pRequiredItem)*/)
	{
		pInventory->AddItem(m_pReward);

		//set hint
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("14",12);


		UE_LOG(LogTemp, Warning, TEXT("Bucket acquired!"));
		Destroy();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("I can't do that"));	//Text balloon for player feedback?
}
