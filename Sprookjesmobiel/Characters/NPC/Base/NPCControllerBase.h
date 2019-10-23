// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCControllerBase.generated.h"

class UBehaviorTree;
class UBlackboardData;
class UBlackboardComponent;

UENUM(BlueprintType)
enum class EAnswer : uint8
{
	ENone		UMETA(DisplayName = "None"),
	ETop		UMETA(DisplayName = "Top"),
	EMiddle		UMETA(DisplayName = "Middle"),
	EBottom		UMETA(DisplayName = "Bottom")
};

UCLASS()
class SPROOKJESMOBIEL_API ANPCControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ANPCControllerBase();

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	virtual void InitBlackboard();

	UPROPERTY(VisibleAnywhere, DisplayName = "Blackboard Component", Category = "Components")
	UBlackboardComponent* m_pBlackboardComp;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Dialogue Tree", Category = "Dialogue")
	UBehaviorTree* m_pDialogueTree;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Dialogue Blackboard", Category = "Dialogue")
	UBlackboardData* m_pDialogueBlackboard;
};