// Fill out your copyright notice in the Description page of Project Settings.

#include "SickPerson3Controller.h"
#include "BehaviorTree/BlackboardComponent.h"

ASickPerson3Controller::ASickPerson3Controller()
{
	//constructor
}

void ASickPerson3Controller::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ASickPerson3Controller::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();
}