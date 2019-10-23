// Fill out your copyright notice in the Description page of Project Settings.

#include "HerbActor.h"

AHerbActor::AHerbActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AHerbActor::BeginPlay()
{
	Super::BeginPlay();	
}

void AHerbActor::Interact(APlayerCharacter* pPlayer)
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with Herb!"));
}