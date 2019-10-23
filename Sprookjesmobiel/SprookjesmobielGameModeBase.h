// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Managers/InputManager.h"
#include "SprookjesmobielGameModeBase.generated.h"

class AParticleManager;
class ASoundManager;

UCLASS()
class SPROOKJESMOBIEL_API ASprookjesmobielGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASprookjesmobielGameModeBase();

	UFUNCTION(BlueprintPure)
	FORCEINLINE AParticleManager* GetParticleManager()
	{
		return m_pParticleManager;
	}
	
	UFUNCTION(BlueprintPure)
	FORCEINLINE ASoundManager* GetSoundManager()
	{
		return m_pSoundManager;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE AInputManager* GetInputManager()
	{
		return m_pInputManager;
	}

	FORCEINLINE bool InDevMode()
	{
		return m_InDevMode;
	}

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Input Manager", Category = "Managers")
	TSubclassOf<AInputManager> m_InputManagerClass;


	UPROPERTY(EditAnywhere, DisplayName = "Particle Manager", Category = "Managers")
	TSubclassOf<AParticleManager> m_ParticleManagerClass;
	
	UPROPERTY(EditAnywhere, DisplayName = "Sound Manager", Category = "Managers")
	TSubclassOf<ASoundManager> m_SoundManagerClass;

	UPROPERTY(EditAnywhere, DisplayName = "Well Women Dialogue", Category = "Dialogues")
	ACharacter* m_pWellWomenCharacter;

	AParticleManager* m_pParticleManager;
	ASoundManager* m_pSoundManager;
	AInputManager* m_pInputManager;

	UPROPERTY(EditAnywhere, DisplayName = "In Dev Mode", Category = "Development")
	bool m_InDevMode;

	//Helper functions
	void SpawnParticleManager();
	void SpawnSoundManager();
	void SpawnInputManager();
};