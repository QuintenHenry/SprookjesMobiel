// Fill out your copyright notice in the Description page of Project Settings.

#include "SickPerson1Pawn.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Particles/ParticleSystemComponent.h"

ASickPerson1Pawn::ASickPerson1Pawn()
{
	//Constructor
}

void ASickPerson1Pawn::BeginPlay()
{
	Super::BeginPlay();

	//Start first NPC, testing
	m_pParticleComp->SetVisibility(true);
}

void ASickPerson1Pawn::Interact(APlayerCharacter* pPlayer)
{
	//Set objective
	FGameInfo& gameInfo = pPlayer->GetGameInfo();

	if (gameInfo.Objective == EObjective::EGoToFirstPerson)
		gameInfo.Objective = EObjective::ECureFirstPerson;

	ANPCPawnBase::Interact(pPlayer);
}