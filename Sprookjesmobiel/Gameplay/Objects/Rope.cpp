// Fill out your copyright notice in the Description page of Project Settings.

#include "Rope.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
// Sets default values
ARope::ARope()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARope::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARope::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ARope::NotifyActorOnInputTouchBegin(ETouchIndex::Type FingerIndex)
{
	UseActor();
}

void ARope::NotifyActorOnClicked(FKey ButtonPressed)
{
	UseActor();
}
void ARope::UseActor() {
	if (m_CanBeCollected) {
		m_WaterWell->AddRope();
		Destroy();
	}
}
void ARope::EnableCollect()
{
	m_CanBeCollected = true;
}

