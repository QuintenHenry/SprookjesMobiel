// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardController.h"

AGuardController::AGuardController()
{
}

void AGuardController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void AGuardController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}