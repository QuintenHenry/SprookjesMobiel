// Fill out your copyright notice in the Description page of Project Settings.

#include "WoodLog.h"
#include "WaterWell.h"
#include "GameFramework/PlayerController.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Engine/World.h"
// Sets default values
AWoodLog::AWoodLog()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_CanBeCollected = false;
}
void AWoodLog::NotifyActorOnInputTouchBegin(ETouchIndex::Type FingerIndex) {
	UseActor();
}
void AWoodLog::NotifyActorOnClicked(FKey ButtonPressed)
{
	UseActor();
}
void AWoodLog::UseActor() {
	if (m_CanBeCollected) {
		m_WaterWell->AddWoodLog();
		Destroy();
	}
}
// Called when the game starts or when spawned
void AWoodLog::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWoodLog::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWoodLog::EnableCollect()
{
	m_CanBeCollected = true;
}

