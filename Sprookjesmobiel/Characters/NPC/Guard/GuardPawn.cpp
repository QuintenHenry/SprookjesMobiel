// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardPawn.h"
#include "Characters/Player/PlayerCharacter.h"

AGuardPawn::AGuardPawn()
{
	//Constructor
}

void AGuardPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AGuardPawn::Interact(APlayerCharacter* pPlayer)
{
	pPlayer->SetActiveNPC(this);
}