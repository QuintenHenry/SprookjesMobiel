// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Characters/Player/PlayerCharacter.h"

AInteractableActor::AInteractableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	//Initialize components
	m_pStaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	RootComponent = m_pStaticMeshComp;

	m_pCollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	m_pCollisionComp->SetupAttachment(RootComponent);

	m_pTriggerComp = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerComp"));
	m_pTriggerComp->SetupAttachment(RootComponent);

	//Bind events
	m_pTriggerComp->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnOverlapBegin);
}

void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractableActor::Interact(APlayerCharacter* pPlayer)
{
	//Default implementation
}

void AInteractableActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(OtherActor);

	if (pCharacter)
	{
		if (pCharacter->GetInteractable() == this)
		{
			Interact(pCharacter);
			pCharacter->SetInteractable(nullptr);
		}
	}
}