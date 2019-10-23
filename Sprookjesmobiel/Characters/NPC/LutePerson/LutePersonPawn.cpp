// Fill out your copyright notice in the Description page of Project Settings.

#include "LutePersonPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

ALutePersonPawn::ALutePersonPawn()
{
	m_pLute = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lute"));
	m_pLute->SetupAttachment(m_pSkeletalMeshComp, FName("LeftMiddleHand_Socket"));

	m_pMusicParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MusicParticle"));
	m_pMusicParticle->SetupAttachment(m_pLute);
}

void ALutePersonPawn::BeginPlay()
{
	Super::BeginPlay();
	
}