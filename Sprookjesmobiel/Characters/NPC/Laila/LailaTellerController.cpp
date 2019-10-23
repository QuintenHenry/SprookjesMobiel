// Fill out your copyright notice in the Description page of Project Settings.

#include "LailaTellerController.h"
#include "BehaviorTree/BlackboardComponent.h"

ALailaTellerController::ALailaTellerController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALailaTellerController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ALailaTellerController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}
