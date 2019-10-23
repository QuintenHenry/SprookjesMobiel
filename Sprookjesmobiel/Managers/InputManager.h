// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MaterialBillboardComponent.h"
#include "GameFramework/Actor.h"
#include "InputManager.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AInputManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void HideShakeIcon();
	UFUNCTION(BlueprintCallable)
	void SetShakingIconPosition(FVector worldpos,bool WaitOnWindows=true);
	UFUNCTION(BlueprintCallable)
	bool GetIsShaking() { return m_Shaking; }
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:


	UMaterialBillboardComponent *m_ShakeBillboard;

	float accelerometerUpdateInterval = 1.0f / 60.0f;
	// The greater the value of LowPassKernelWidthInSeconds, the slower the
	// filtered value will converge towards current input sample (and vice versa).
	float lowPassKernelWidthInSeconds = 1.0f;
	// This next parameter is initialized to 2.0 per Apple's recommendation,
	// or at least according to Brady! ;)
	float shakeDetectionThreshold = 2.0f;

	float lowPassFilterFactor;
	FVector lowPassValue;

	FTimerHandle m_Timer;
	//shaking
	bool m_Shaking{};
};
