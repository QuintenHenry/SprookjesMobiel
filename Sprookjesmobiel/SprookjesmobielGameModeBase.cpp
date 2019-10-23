// Fill out your copyright notice in the Description page of Project Settings.

#include "SprookjesmobielGameModeBase.h"
#include "Managers/ParticleManager.h"
#include "Managers/SoundManager.h"
#include "Engine/World.h"

ASprookjesmobielGameModeBase::ASprookjesmobielGameModeBase()
{
	m_InDevMode = true;
}

void ASprookjesmobielGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	SpawnParticleManager();
	SpawnSoundManager();
	SpawnInputManager();

}

void ASprookjesmobielGameModeBase::SpawnParticleManager()
{
	if (!m_ParticleManagerClass)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode: Could not spawn particle manager, no class specified"));
		return;
	}

	UWorld* pWorld = GetWorld();
	if (pWorld)
		m_pParticleManager = pWorld->SpawnActor<AParticleManager>(m_ParticleManagerClass);
}

void ASprookjesmobielGameModeBase::SpawnSoundManager()
{
	if (!m_SoundManagerClass)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode: Could not spawn sound manager, no class specified"));
		return;
	}

	UWorld* pWorld = GetWorld();
	if (pWorld)
		m_pSoundManager = pWorld->SpawnActor<ASoundManager>(m_SoundManagerClass);

}

void ASprookjesmobielGameModeBase::SpawnInputManager()
{
	if (!m_InputManagerClass)
	{
		UE_LOG(LogTemp, Error, TEXT("GameMode: Could not spawn input manager, no class specified"));
		return;
	}

	UWorld* pWorld = GetWorld();
	if (pWorld)
		m_pInputManager = pWorld->SpawnActor<AInputManager>(m_InputManagerClass);

}