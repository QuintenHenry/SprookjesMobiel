// Fill out your copyright notice in the Description page of Project Settings.

#include "PrincessCuredController.h"
#include "BehaviorTree/BlackboardComponent.h"

APrincessCuredController::APrincessCuredController()
{
	//constructor
}

void APrincessCuredController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void APrincessCuredController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("CanMarry"), false);
}

void APrincessCuredController::EnableMarriage()
{
	m_pBlackboardComp->SetValueAsBool(FName("CanMarry"), true);
}