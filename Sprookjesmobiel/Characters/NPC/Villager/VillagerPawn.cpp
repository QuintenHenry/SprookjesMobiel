// Fill out your copyright notice in the Description page of Project Settings.

#include "VillagerPawn.h"
#include "Sprookjesmobiel/SprookjesmobielGameModeBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimSingleNodeInstance.h"
#include "Managers/SoundManager.h"
#include "Animation/AnimSequence.h"
#include "TimerManager.h"

AVillagerPawn::AVillagerPawn()
{
	m_Pitch = FMath::FRandRange(0.9f,1.2f);
}

void AVillagerPawn::Tick(float DeltaSeconds)
{
	if (m_CurrentTimer <= m_PlaySoundTimer)
		m_CurrentTimer += DeltaSeconds;
}

void AVillagerPawn::Interact(APlayerCharacter* pPlayer)
{
	if (m_CurrentTimer<m_PlaySoundTimer)
		return;

	//ANIMATION
	PlayWave();

	//SOUND
	ASprookjesmobielGameModeBase* gamemode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!gamemode) return;
	gamemode->GetSoundManager()->PlaySound("Hallo",m_Pitch);

	m_CurrentTimer = 0.0f;
	ANPCPawnBase::Interact(pPlayer);
}
