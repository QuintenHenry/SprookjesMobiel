// Fill out your copyright notice in the Description page of Project Settings.

#include "WellWomenController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Components/StaticMeshComponent.h"

AWellWomenController::AWellWomenController()
{
	PrimaryActorTick.bCanEverTick = true;
	m_CanBeDestroyed = false;
}

void AWellWomenController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	/*if(!m_CanBeDestroyed)
	{
		APlayerCharacter* pCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if(pCharacter && pCharacter->GetGameInfo().HaveWomenSpoken)
			m_CanBeDestroyed = true;
	}
	else
	{
		m_DestroyCountDown -= deltaTime;
		if(m_DestroyCountDown <= 0)
		{
			TArray<AActor*> pArray;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), m_pCaravanClass, pArray);
			if(pArray.Num() > 0)
			{
				//pArray[0]->FindComponentByClass<UStaticMeshComponent>()->SetVisibility(true);
				pArray[0]->SetActorHiddenInGame(false);
			}
			//GetWorld()->SpawnActor(m_pCaravanClass);
			GetPawn()->Destroy();
			Destroy();
		}
	}*/
}

void AWellWomenController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void AWellWomenController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}