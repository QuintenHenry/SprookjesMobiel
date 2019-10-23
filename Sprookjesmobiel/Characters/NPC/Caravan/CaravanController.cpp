// Fill out your copyright notice in the Description page of Project Settings.

#include "CaravanController.h"

ACaravanController::ACaravanController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACaravanController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ACaravanController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}
