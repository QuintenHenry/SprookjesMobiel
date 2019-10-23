// Fill out your copyright notice in the Description page of Project Settings.

#include "SultanController.h"
#include "BehaviorTree/BlackboardComponent.h"

ASultanController::ASultanController()
{
	//Constructor
}

void ASultanController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ASultanController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
	m_pBlackboardComp->SetValueAsBool(FName("IsPrincessCured"), false);
}

//TESTING REMOVE WITH EVENT SYSTEM
void ASultanController::CurePrincess()
{
	m_pBlackboardComp->SetValueAsBool(FName("IsPrincessCured"), true);
}