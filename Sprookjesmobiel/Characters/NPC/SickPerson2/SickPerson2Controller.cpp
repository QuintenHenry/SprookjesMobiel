// Fill out your copyright notice in the Description page of Project Settings.

#include "SickPerson2Controller.h"
#include "BehaviorTree/BlackboardComponent.h"

ASickPerson2Controller::ASickPerson2Controller()
{
	//Constructor
}

void ASickPerson2Controller::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ASickPerson2Controller::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsClass(FName("RequiredItem"), nullptr);
}