// Fill out your copyright notice in the Description page of Project Settings.

#include "InputManager.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include <EngineGlobals.h>
#include "Components/MaterialBillboardComponent.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "SprookjesmobielGameModeBase.h"
#include "Managers/ParticleManager.h"
#include "TimerManager.h"
// Sets default values
AInputManager::AInputManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void AInputManager::BeginPlay()
{
	TArray<UMaterialBillboardComponent*> Comps;
	//get Billboard component
	GetComponents(Comps);
	if (Comps.Num() > 0)
	{
		m_ShakeBillboard = Comps[0];
	}




	Super::BeginPlay();
	lowPassFilterFactor = accelerometerUpdateInterval / lowPassKernelWidthInSeconds;
	shakeDetectionThreshold *= shakeDetectionThreshold;


	FVector tilt;
	FVector rot;
	FVector gravity;
	FVector acceleration;
	GetWorld()->GetFirstPlayerController()->GetInputMotionState(tilt, rot, gravity, acceleration);
	lowPassValue = acceleration;
}

void AInputManager::HideShakeIcon()
{
	//m_ShakeBillboard->SetVisibility(false);

	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	AParticleManager* pParticleManager = pGameMode->GetParticleManager();

	if (pParticleManager)
		pParticleManager->StopShakeParticle();

}

void AInputManager::SetShakingIconPosition(FVector worldpos,bool WaitOnWindows)
{
	//m_ShakeBillboard->SetVisibility(true);
	
	//m_ShakeBillboard->SetWorldLocation(worldpos);

	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	AParticleManager* pParticleManager = pGameMode->GetParticleManager();

	if (pParticleManager)
		pParticleManager->SpawnParticle("Shake", worldpos);

	/*
	auto function = [this]() {m_Shaking = true; };
	if (UGameplayStatics::GetPlatformName() != "IOS") {
		if (WaitOnWindows)
			GetWorldTimerManager().SetTimer(m_Timer, function, 3.0f, false);
		else
			m_Shaking = true;
	}
	*/
}

// Called every frame
void AInputManager::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	if (UGameplayStatics::GetPlatformName() != "IOS")
	{
		m_Shaking = true;
		return;
	}
	if (m_Shaking)
		m_Shaking = false;

	FVector tilt;
	FVector rotation;
	FVector gravity;
	FVector acceleration;
	GetWorld()->GetFirstPlayerController()->GetInputMotionState(tilt, rotation, gravity, acceleration);

	lowPassValue = UKismetMathLibrary::VLerp(lowPassValue, acceleration, lowPassFilterFactor);
	FVector deltaAcceleration = acceleration - lowPassValue;

	if (deltaAcceleration.SizeSquared() >= shakeDetectionThreshold)
	{
		//shaking

		m_Shaking = true;
	}
}


