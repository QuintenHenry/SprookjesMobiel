// Fill out your copyright notice in the Description page of Project Settings.

#include "CamelPawn.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimSequence.h"
#include "Animation/AnimSingleNodeInstance.h"
#include "TimerManager.h"

ACamelPawn::ACamelPawn()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACamelPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ACamelPawn::Interact(APlayerCharacter* pPlayer)
{
	m_pSkeletalMeshComp->PlayAnimation(m_pShakeAnimation, false);
	float animLength = m_pSkeletalMeshComp->GetSingleNodeInstance()->GetLength();

	GetWorldTimerManager().SetTimer(m_AnimHandle, this, &ACamelPawn::IdleAnimationHandler, animLength, false);

	ANPCPawnBase::Interact(pPlayer);
}

void ACamelPawn::IdleAnimationHandler()
{
	m_pSkeletalMeshComp->PlayAnimation(m_pIdleAnimation, true);
}