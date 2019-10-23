// Fill out your copyright notice in the Description page of Project Settings.

#include "ThroneActor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Runtime/NavigationSystem/Public/AbstractNavData.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Characters/Player/MainPlayerController.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AThroneActor::AThroneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_pStartTarget = CreateDefaultSubobject<UArrowComponent>(TEXT("StartTarget"));
	//RootComponent = Cast<USceneComponent>(m_pStaticMeshComp);
	m_pStartTarget->SetupAttachment(RootComponent);
}

void AThroneActor::Interact(APlayerCharacter * pPlayer)
{
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(pPlayer->GetController(), m_pStartTarget->GetComponentLocation());

	Cast<AMainPlayerController>(pPlayer->GetController())->SetEnableMove(false);
	m_pPlayerCharacter = pPlayer;
	m_PlayerSitting = true;
	m_pAnimationInstance = m_pPlayerCharacter->GetMesh()->GetAnimInstance();
}

// Called when the game starts or when spawned
void AThroneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AThroneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (!m_PlayerSitting)
		return;
	
	if (m_pPlayerCharacter->GetMovementComponent()->Velocity.Size() < 10.0f)
	{
		m_pPlayerCharacter->SetActorRotation(FMath::Lerp(m_pPlayerCharacter->GetActorRotation(), m_pStartTarget->GetComponentRotation(), 0.08f));
	}

	float differenceRot = UKismetMathLibrary::NormalizedDeltaRotator(m_pPlayerCharacter->GetActorRotation(), m_pStartTarget->GetComponentRotation()).Yaw;
	if (FMath::Abs(differenceRot)< 2.0f)
	{
		m_pPlayerCharacter->SetSitting(true);
		m_PlayerSitting = false;
		//Cast<AMainPlayerController>(m_pPlayerCharacter->GetController())->SetEnableMove(false);
	}
}

