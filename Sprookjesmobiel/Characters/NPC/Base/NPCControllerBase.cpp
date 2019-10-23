// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCControllerBase.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "Characters/Player/PlayerCharacter.h"

ANPCControllerBase::ANPCControllerBase()
{
	//Initialize component
	m_pBlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	//Set default values
	m_pDialogueTree = nullptr;
	m_pDialogueBlackboard = nullptr;
}

void ANPCControllerBase::BeginPlay()
{
	Super::BeginPlay();

	bool result = UseBlackboard(m_pDialogueBlackboard, m_pBlackboardComp);

	if (!result)
		UE_LOG(LogTemp, Warning, TEXT("Could not link blackboard to NPC"));
}

void ANPCControllerBase::InitBlackboard()
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (pCharacter)
		m_pBlackboardComp->SetValueAsObject(FName("Player"), pCharacter);
	
	AHUD* pHUD = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD();
	if (pHUD)
		m_pBlackboardComp->SetValueAsObject(FName("HUD"), pHUD);
}