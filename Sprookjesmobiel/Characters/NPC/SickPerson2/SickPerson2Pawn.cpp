// Fill out your copyright notice in the Description page of Project Settings.

#include "SickPerson2Pawn.h"
#include "Characters/Player/PlayerCharacter.h"

ASickPerson2Pawn::ASickPerson2Pawn()
{
	//Constructor
}

void ASickPerson2Pawn::BeginPlay()
{
	Super::BeginPlay();
}

void ASickPerson2Pawn::Interact(APlayerCharacter* pPlayer)
{
	//Set objective
	FGameInfo& gameInfo = pPlayer->GetGameInfo();

	if (gameInfo.Objective == EObjective::EGoToSecondPerson)
		gameInfo.Objective = EObjective::ECureSecondPerson;

	ANPCPawnBase::Interact(pPlayer);
}