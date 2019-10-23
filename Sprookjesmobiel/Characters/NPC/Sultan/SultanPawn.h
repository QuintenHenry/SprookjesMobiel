// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/NPC/Base/NPCPawnBase.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "SultanPawn.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API ASultanPawn : public ANPCPawnBase
{

	GENERATED_BODY()

public:
	ASultanPawn();
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FVector m_Goal{};
	UArrowComponent *m_pWalkTarget;
	UFloatingPawnMovement *m_pMovementComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,DisplayName = "Walking", Category = "Default", Meta = (AllowPrivateAccess = "true"))
		bool m_Walking{};
};