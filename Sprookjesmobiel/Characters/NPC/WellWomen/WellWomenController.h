// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "WellWomenController.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API AWellWomenController : public ANPCControllerBase
{
	GENERATED_BODY()
	
public:
	AWellWomenController();

protected:
	virtual void Tick(float deltaTime) override;
	virtual void BeginPlay() override;
	virtual void InitBlackboard() override;

private:
	bool m_CanBeDestroyed;
	UPROPERTY(EditAnywhere, DisplayName = "Destroy Contdown", Category = "Default")
	float m_DestroyCountDown;

	UPROPERTY(EditDefaultsOnly, DisplayName = "CaravanClass", Category = "Default")
	TSubclassOf<AActor> m_pCaravanClass;
};
