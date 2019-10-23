// Fill out your copyright notice in the Description page of Project Settings.

#include "Sultan2Controller.h"
#include "BehaviorTree/BlackboardComponent.h"

ASultan2Controller::ASultan2Controller()
{
	//Constructor
}

void ASultan2Controller::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void ASultan2Controller::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("HasIntroduced"), false);
	m_pBlackboardComp->SetValueAsBool(FName("IsPrincessCured"), false);
	m_pBlackboardComp->SetValueAsBool(FName("HasOfferedMarriage"), false);
}

//TESTING REMOVE WITH EVENT SYSTEM
void ASultan2Controller::CurePrincess()
{
	m_pBlackboardComp->SetValueAsBool(FName("IsPrincessCured"), true);
}