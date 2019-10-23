// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "LutePersonPawn.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ALutePersonPawn : public ANPCPawnBase
{
	GENERATED_BODY()
	ALutePersonPawn();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, DisplayName = "MusicParticle", Category = "Components")
	UParticleSystemComponent* m_pMusicParticle;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere, DisplayName = "Lute", Category = "Components")
	UStaticMeshComponent* m_pLute;
	
};
