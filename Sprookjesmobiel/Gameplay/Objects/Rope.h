// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WaterWell.h"
#include "Rope.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ARope : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARope();
	void NotifyActorOnClicked(FKey ButtonPressed) override;
	void NotifyActorOnInputTouchBegin(ETouchIndex::Type FingerIndex) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void EnableCollect();

public:
	UPROPERTY(EditAnywhere, DisplayName = "WaterWell", Category = "Default")
	AWaterWell *m_WaterWell;

private:
	void UseActor();
	bool m_CanBeCollected;

};
