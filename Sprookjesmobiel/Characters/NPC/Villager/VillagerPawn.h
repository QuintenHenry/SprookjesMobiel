// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "VillagerPawn.generated.h"

/**
 * 
 */

class UAnimSequence;

UCLASS()
class SPROOKJESMOBIEL_API AVillagerPawn : public ANPCPawnBase
{
	GENERATED_BODY()
public:
	AVillagerPawn();
	void Tick(float DeltaSeconds) override;
	void Interact(APlayerCharacter *pPlayer) override;
	UFUNCTION(BlueprintImplementableEvent)
	void PlayWave();
private:

	float m_Pitch;
	float m_CurrentTimer = 0.0f;
	float m_PlaySoundTimer = 3.0f;

};
