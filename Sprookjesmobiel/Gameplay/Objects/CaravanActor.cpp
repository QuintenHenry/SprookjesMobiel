// Fill out your copyright notice in the Description page of Project Settings.

#include "CaravanActor.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Characters/Player/PlayerCharacter.h"

// Sets default values
ACaravanActor::ACaravanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACaravanActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACaravanActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if(!bHidden)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if(pCharacter)
		{
			pCharacter->GetGameInfo().HasCaravanArrived = true;
		}
	}*/
}

