// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundManager.generated.h"

class USoundCue;
class UAudioComponent;

USTRUCT(BlueprintType)
struct FSound
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, DisplayName = "Name")
	FString Name;

	UPROPERTY(EditAnywhere, DisplayName = "Sound")
	USoundCue* pSoundCue;
};

UCLASS()
class SPROOKJESMOBIEL_API ASoundManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ASoundManager();

	UFUNCTION(BlueprintCallable)
	void PlaySound(const FString& name,float pitch = 1.0f);

	UFUNCTION(BlueprintCallable)
	void PlayBackground(const FString& name);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, DisplayName = "AudioComponent", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UAudioComponent* m_pAudioComponent;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Sounds", Category = "Audio")
	TArray<FSound> m_Sounds;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Background", Category = "Audio")
	TArray<FSound> m_Backgrounds;
};