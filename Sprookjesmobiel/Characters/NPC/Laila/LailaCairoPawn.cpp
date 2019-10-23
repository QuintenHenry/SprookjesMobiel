// Fill out your copyright notice in the Description page of Project Settings.

#include "LailaCairoPawn.h"
#include "Engine/World.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
// Sets default values
ALailaCairoPawn::ALailaCairoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALailaCairoPawn::Interact(APlayerCharacter * pPlayer)
{
	Super::Interact(pPlayer);
}

// Called when the game starts or when spawned
void ALailaCairoPawn::BeginPlay()
{
	Super::BeginPlay();


	//ANPCPawnBase::Interact(Cast<APlayerCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()));
	
}


