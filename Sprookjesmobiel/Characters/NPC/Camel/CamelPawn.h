// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "CamelPawn.generated.h"

class UAnimSequence;

UCLASS()
class SPROOKJESMOBIEL_API ACamelPawn : public ANPCPawnBase
{
	GENERATED_BODY()
	
public:
	ACamelPawn();

	virtual void Interact(APlayerCharacter* pPlayer) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Idle Animation", Category = "Animation") 
	UAnimSequence* m_pIdleAnimation;

	UPROPERTY(EditAnywhere, DisplayName = "Shake Animation", Category = "Animation") 
	UAnimSequence* m_pShakeAnimation;

	FTimerHandle m_AnimHandle;
	void IdleAnimationHandler();
};