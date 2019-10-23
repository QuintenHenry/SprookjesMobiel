// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCPawnBase.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Characters/Player/PlayerCharacter.h"

ANPCPawnBase::ANPCPawnBase()
{
	PrimaryActorTick.bCanEverTick = false;

	//Initialize components
	m_pTriggerComp = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerComponent"));
	RootComponent = m_pTriggerComp;

	m_pCapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	m_pCapsuleComp->SetupAttachment(RootComponent);

	m_pSkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	m_pSkeletalMeshComp->SetupAttachment(m_pCapsuleComp);

	m_pParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	m_pParticleComp->SetupAttachment(m_pSkeletalMeshComp);

	//Bind events
	m_pTriggerComp->OnComponentBeginOverlap.AddDynamic(this, &ANPCPawnBase::OnOverlapBegin);
	m_pTriggerComp->OnComponentEndOverlap.AddDynamic(this, &ANPCPawnBase::OnOverlapEnd);

	//Set default value
	m_IsPlayerClose = false;
}

void ANPCPawnBase::BeginPlay()
{
	Super::BeginPlay();	
}

void ANPCPawnBase::Interact(APlayerCharacter* pPlayer)
{
	pPlayer->SetActiveNPC(this);
}

void ANPCPawnBase::ShowQuestMarker(bool visible)
{
	m_pParticleComp->SetVisibility(visible);
}

void ANPCPawnBase::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(OtherActor);

	if (pCharacter)
	{
		m_IsPlayerClose = true;
		AActor* pInter = pCharacter->GetInteractable();
		if (pCharacter->GetInteractable() == this)
		{
			Interact(pCharacter);
			pCharacter->SetInteractable(nullptr);
		}
	}
}

void ANPCPawnBase::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->IsA<APlayerCharacter>())
		m_IsPlayerClose = false;
}