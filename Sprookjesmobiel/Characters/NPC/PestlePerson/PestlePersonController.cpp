// Fill out your copyright notice in the Description page of Project Settings.

#include "PestlePersonController.h"
#include "BehaviorTree/BlackboardComponent.h"

APestlePersonController::APestlePersonController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APestlePersonController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void APestlePersonController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
}
