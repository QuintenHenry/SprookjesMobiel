// Fill out your copyright notice in the Description page of Project Settings.

#include "SoundManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"

ASoundManager::ASoundManager()
{
	PrimaryActorTick.bCanEverTick = false;

	m_pAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent"));
}

void ASoundManager::BeginPlay()
{
	Super::BeginPlay();
}

void ASoundManager::PlaySound(const FString& name,float pitch)
{
	FSound* pSound = m_Sounds.FindByPredicate([name](const FSound& element) { 
		return element.Name.Equals(name);
	});

	if (pSound)
		UGameplayStatics::PlaySound2D(GetWorld(), pSound->pSoundCue, 1.0, pitch);
	else
		UE_LOG(LogTemp, Warning, TEXT("SoundManager::PlaySound - Sound not found"));
}

void ASoundManager::PlayBackground(const FString& name)
{
	FSound* pBackground = m_Backgrounds.FindByPredicate([name](const FSound& element) { 
		return element.Name.Equals(name);
	});

	if (pBackground)
	{
		m_pAudioComponent->SetSound(pBackground->pSoundCue);
		m_pAudioComponent->Play();
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("SoundManager::PlayBackground - Sound not found"));
}