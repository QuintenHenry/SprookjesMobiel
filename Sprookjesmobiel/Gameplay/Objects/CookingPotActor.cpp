// Fill out your copyright notice in the Description page of Project Settings.

#include "CookingPotActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Gameplay/Items/BaseItem.h"
#include "UI/InventoryWidget.h"
#include "Sprookjesmobiel/UI/HintWidget.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"

ACookingPotActor::ACookingPotActor()
{
	PrimaryActorTick.bCanEverTick = false;

	m_pFireComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("FireComponent"));
	m_pFireComponent->SetupAttachment(RootComponent);

	m_pAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
	m_pAudioComponent->SetupAttachment(RootComponent);

	m_IsFireOn = false;
}

void ACookingPotActor::BeginPlay()
{
	Super::BeginPlay();
}

void ACookingPotActor::Interact(APlayerCharacter* pPlayer)
{
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	UBaseItem* pItem = pInventory->GetSelectedItem();

	if (m_pRequiredItem && pItem && m_pExtraRequired)
	{
		if (pItem->IsA(m_pRequiredItem) && !m_IsFireOn) 
		{
			pInventory->RemoveItem(m_pRequiredItem);
			//Fire!
			m_pFireComponent->SetVisibility(true);
			m_pAudioComponent->Play();
			m_IsFireOn = true;			
		}
		if(m_IsFireOn && pItem->IsA(m_pExtraRequired) && !pInventory->Contains(m_pReward))
		{
			pInventory->AddItem(m_pReward);

			//set hint
			ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
			hud->GetHintWidget()->SetNewHint("2");
		}
		//else: show error
	}

	pInventory->ClearSelectedItem();
}