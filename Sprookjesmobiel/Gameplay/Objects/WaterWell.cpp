// Fill out your copyright notice in the Description page of Project Settings.

#include "WaterWell.h"
#include "Components/StaticMeshComponent.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/HintWidget.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SprookjesmobielHUD.h"

AWaterWell::AWaterWell()
{
	PrimaryActorTick.bCanEverTick = false;

	//Initialize components
	m_pWellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WellMesh"));
	RootComponent = m_pWellMesh;

	m_pLog1Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Log1Mesh"));
	m_pLog1Mesh->SetupAttachment(RootComponent);

	m_pLog2Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Log2Mesh"));
	m_pLog2Mesh->SetupAttachment(RootComponent);

	m_pLog3Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Log3Mesh"));
	m_pLog3Mesh->SetupAttachment(RootComponent);

	m_pRopeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RopeMesh"));
	m_pRopeMesh->SetupAttachment(RootComponent);
}

void AWaterWell::BeginPlay()
{
	Super::BeginPlay();

	m_pMushin = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AWaterWell::SpawnMushin() 
{
	m_CanSpawnMuhsin = true;
	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(pController)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(pController->GetHUD());
		if(pHUD)
		{
			pHUD->ActivateLoadingScreen();
		}
	}
}

void AWaterWell::AddWoodLog()
{
	++m_CurrentLogs;

	if (m_CurrentLogs==1)
	{
		m_pLog1Mesh->SetMaterial(0, m_WellMaterial);
		return;
	}

	if (m_CurrentLogs == 2)
	{
		m_pLog2Mesh->SetMaterial(0, m_WellMaterial);
		return;
	}

	if (m_CurrentLogs == 3)
	{
		m_pLog3Mesh->SetMaterial(0, m_WellMaterial);

		if (m_CurrentLogs == m_RequiredLogs && (m_pRopeMesh->GetMaterial(0)==m_WellMaterial))
			SetCompleted();
	}
}

void AWaterWell::AddRope() 
{
	m_pRopeMesh->SetMaterial(0, m_WellMaterial);

	if(m_CurrentLogs >= m_RequiredLogs)
		SetCompleted();
}

void AWaterWell::SetCompleted()
{
	m_IsCompleted = true;
	//set hint
	ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	hud->GetHintWidget()->SetNewHint("2");

}