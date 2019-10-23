// Fill out your copyright notice in the Description page of Project Settings.

#include "CamelController.h"
#include "BehaviorTree/BlackboardComponent.h"

ACamelController::ACamelController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACamelController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ACamelController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
}