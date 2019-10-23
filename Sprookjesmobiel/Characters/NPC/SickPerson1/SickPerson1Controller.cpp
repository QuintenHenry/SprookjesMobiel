// Fill out your copyright notice in the Description page of Project Settings.

#include "SickPerson1Controller.h"
#include "BehaviorTree/BlackboardComponent.h"

ASickPerson1Controller::ASickPerson1Controller()
{
	//Constructor
}

void ASickPerson1Controller::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);

}

void ASickPerson1Controller::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsClass(FName("RequiredObject"), nullptr);
}