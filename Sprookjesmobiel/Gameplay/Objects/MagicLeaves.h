// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "Gameplay/Items/BaseItem.h"
#include "MagicLeaves.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API AMagicLeaves : public AInteractableActor
{
	GENERATED_BODY()
public:
	void Interact(APlayerCharacter* pPlayer) override;
	void Tick(float deltaTime) override;
private:
	bool m_CanShake{};
	bool m_HasTakenLeaves{};
	
	UPROPERTY(EditAnywhere, DisplayName = "Magic Leaves Item", Category = "Default")
	TSubclassOf<UBaseItem> m_MagicLeavesItem;
	UPROPERTY(EditAnywhere, DisplayName = "ShakeThreshHold", Category = "Default")
	float m_ShakeTreshhold=1.0f;

};
