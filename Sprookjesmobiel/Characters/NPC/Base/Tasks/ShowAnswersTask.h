// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "ShowAnswersTask.generated.h"

class UDialogueWidget;

UCLASS()
class SPROOKJESMOBIEL_API UShowAnswersTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UShowAnswersTask();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "HUD Key", Category = "Input")
	FBlackboardKeySelector m_HUDKey;

	UPROPERTY(EditAnywhere, DisplayName = "Answer Key", Category = "Input")
	FBlackboardKeySelector m_AnswerKey;

	UPROPERTY(EditAnywhere, DisplayName = "Top", Category = "Input")
	FString m_TopAnswer;

	UPROPERTY(EditAnywhere, DisplayName = "Middle", Category = "Input")
	FString m_MiddleAnswer;

	UPROPERTY(EditAnywhere, DisplayName = "Bottom", Category = "Input")
	FString m_BottomAnswer;

	//Blackboard reference
	UBlackboardComponent* m_pBlackboard;

	//Helper functions
	EBTNodeResult::Type BindAnswerEvent(UBehaviorTreeComponent& OwnerComp, UDialogueWidget* pWidget);

	UFUNCTION()
	void SetAnswer(EAnswer answer);
};
