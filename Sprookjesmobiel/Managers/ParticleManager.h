// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "ParticleManager.generated.h"

class UParticleSystem;

USTRUCT(BlueprintType)
struct FParticle
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, DisplayName = "Name")
	FString Name;

	UPROPERTY(EditAnywhere, DisplayName = "Particle")
	UParticleSystem* pParticleSystem;
};


UCLASS()
class SPROOKJESMOBIEL_API AParticleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AParticleManager();


	UFUNCTION(BlueprintCallable)
	void SpawnParticle(const FString& name, const FVector& worldPos);
	//void SpawnParticle(const FString& name, const FVector& worldPos, const FVector scale);
	void StopShakeParticle();

	//UFUNCTION(BlueprintCallable);
	void StopSwipeParticle();
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, DisplayName = "Particles", Category = "Particles")
	TArray<FParticle> m_Particles;

	/*UPROPERTY()
	TArray<UParticleSystemComponent*> m_SpawnedParticles;*/

	UPROPERTY()
	UParticleSystemComponent* m_pShakeParticle;

	UPROPERTY()
	UParticleSystemComponent* m_pSwipeParticle;
};
