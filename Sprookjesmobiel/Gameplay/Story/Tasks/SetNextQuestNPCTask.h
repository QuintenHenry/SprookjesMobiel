// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetNextQuestNPCTask.generated.h"

class ANPCPawnBase;
class UParticleSystemComponent;

UCLASS()
class SPROOKJESMOBIEL_API USetNextQuestNPCTask : public UBTTaskNode
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Self Key", Category = "Input")
	FBlackboardKeySelector m_SelfKey;

	UPROPERTY(EditAnywhere, DisplayName = "Next NPC", Category = "Input")
	TSubclassOf<ANPCPawnBase> m_pNextNPCClass;

	//Helper function
	ANPCPawnBase* GetNextNPC();
};