// Fill out your copyright notice in the Description page of Project Settings.

#include "MusaController.h"

AMusaController::AMusaController()
{
}

void AMusaController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void AMusaController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}

