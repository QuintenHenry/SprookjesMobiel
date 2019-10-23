// Fill out your copyright notice in the Description page of Project Settings.

#include "DeliveryPersonController.h"
#include "BehaviorTree/BlackboardComponent.h"

ADeliveryPersonController::ADeliveryPersonController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ADeliveryPersonController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ADeliveryPersonController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
}