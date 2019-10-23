// Fill out your copyright notice in the Description page of Project Settings.

#include "PrincessCuredPawn.h"

APrincessCuredPawn::APrincessCuredPawn()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APrincessCuredPawn::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}