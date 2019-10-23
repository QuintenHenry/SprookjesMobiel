// Fill out your copyright notice in the Description page of Project Settings.

#include "Sultan1Controller.h"
#include "BehaviorTree/BlackboardComponent.h"

ASultan1Controller::ASultan1Controller()
{
	//Constructor
}

void ASultan1Controller::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ASultan1Controller::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
	m_pBlackboardComp->SetValueAsEnum(FName("Answer"), static_cast<uint8>(EAnswer::ENone));
}