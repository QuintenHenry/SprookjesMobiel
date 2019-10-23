// Fill out your copyright notice in the Description page of Project Settings.

#include "PrincessController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/NPC/Princess/PrincessPawn.h"

APrincessController::APrincessController()
{
	//constructor
}

void APrincessController::BeginPlay()
{
	Super::BeginPlay();

	InitBlackboard();
	RunBehaviorTree(m_pDialogueTree);
}

void APrincessController::InitBlackboard()
{
	ANPCControllerBase::InitBlackboard();

	m_pBlackboardComp->SetValueAsClass(FName("RequiredItem"), nullptr);
	m_pBlackboardComp->SetValueAsBool(FName("HasFever"), true);
	m_pBlackboardComp->SetValueAsBool(FName("NeedsTea"), true);
}