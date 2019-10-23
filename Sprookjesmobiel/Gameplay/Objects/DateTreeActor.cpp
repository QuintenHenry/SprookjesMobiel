// Fill out your copyright notice in the Description page of Project Settings.

#include "DateTreeActor.h"
#include "Engine/World.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Characters/Player/PlayerCharacter.h"
#include "SprookjesmobielGameModeBase.h"
#include "UI/InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimSequence.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Characters/Player/MainPlayerController.h"
#include "Animation/AnimSingleNodeInstance.h"
#include "TimerManager.h"
#include "Gameplay/Objects/DateActor.h"

ADateTreeActor::ADateTreeActor()
{
	m_pSpawnPos = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPos"));
	m_pSpawnPos->SetupAttachment(m_pStaticMeshComp);

	m_pSkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	m_pSkeletalMeshComp->SetupAttachment(m_pStaticMeshComp);

}

void ADateTreeActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADateTreeActor::Interact(APlayerCharacter* pPlayer)
{
	if (m_TookDates)
		return;

	//Check for selected item
	UInventoryWidget* pInventory = pPlayer->GetInventory();
	if (pInventory->GetSelectedItem())
	{
		UE_LOG(LogTemp, Warning, TEXT("I can't do that."));
		pInventory->ClearSelectedItem();
		return;
	}

	m_CanTakeDates = true;

	ASprookjesmobielGameModeBase* gamemode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!gamemode) return;

	gamemode->GetInputManager()->HideShakeIcon();
	FVector offset{ -100.0f,0.0f,200.0f };
	gamemode->GetInputManager()->SetShakingIconPosition(GetActorLocation() + offset);
}

void ADateTreeActor::Tick(float DeltaTime)
{
	if (!m_CanTakeDates)
		return;


	ASprookjesmobielGameModeBase* gamemode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!gamemode) return;
	//Shake
	if (gamemode->GetInputManager()->GetIsShaking())
	{
		UWorld* pWorld = GetWorld();
		if (pWorld && m_pDateClass)
		{
			FVector spawnPos = m_pSpawnPos->GetComponentLocation();
			if(m_pDateArray.Num() < m_MaxNrDates)
			{
				ADateActor* date = pWorld->SpawnActor<ADateActor>(m_pDateClass, spawnPos, UKismetMathLibrary::RandomRotator());
				m_pDateArray.Push(date);
			}
			else
			{
				if (IsValid(m_pDateArray[m_OldestIdx]))
				{
					ADateActor* pDateActor = m_pDateArray[m_OldestIdx];
					pDateActor->TeleportTo(spawnPos, UKismetMathLibrary::RandomRotator(), true, true);
					pDateActor->Enable();
				}
				else
				{
					m_pDateArray[m_OldestIdx] = nullptr;
					m_pDateArray[m_OldestIdx] = pWorld->SpawnActor<ADateActor>(m_pDateClass, spawnPos, UKismetMathLibrary::RandomRotator());
				}
				++m_OldestIdx;
				if(m_OldestIdx > m_MaxNrDates - 1)
					m_OldestIdx = 0;
			}

			//Animation
			m_pSkeletalMeshComp->PlayAnimation(m_pShakeAnimation, false);
			float animLength = m_pSkeletalMeshComp->GetSingleNodeInstance()->GetLength();

			GetWorldTimerManager().SetTimer(m_AnimHandle, this, &ADateTreeActor::IdleAnimationHandler, animLength, false);
		}
		else
			UE_LOG(LogTemp, Warning, TEXT("DateTreeActor::Interact - No date class specified!"));

		m_CanTakeDates = false;
		m_TookDates = true;
		gamemode->GetInputManager()->HideShakeIcon();
	}
}

void ADateTreeActor::IdleAnimationHandler()
{
	m_pSkeletalMeshComp->PlayAnimation(m_pIdleAnimation, true);
	m_TookDates = false;
}