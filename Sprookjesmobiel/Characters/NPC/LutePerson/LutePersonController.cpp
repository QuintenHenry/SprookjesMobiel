// Fill out your copyright notice in the Description page of Project Settings.

#include "LutePersonController.h"
#include "BehaviorTree/BlackboardComponent.h"

ALutePersonController::ALutePersonController()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ALutePersonController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ALutePersonController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
	m_pBlackboardComp->SetValueAsBool(FName("HasGivenLute"), false);
}