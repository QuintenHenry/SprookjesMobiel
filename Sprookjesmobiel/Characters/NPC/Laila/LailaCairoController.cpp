// Fill out your copyright notice in the Description page of Project Settings.

#include "LailaCairoController.h"
#include "BehaviorTree/BlackboardComponent.h"

ALailaCairoController::ALailaCairoController()
{
	//Constructor
}

void ALailaCairoController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);


}

void ALailaCairoController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsBool(FName("IsIntro"), true);
}