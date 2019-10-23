// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UI/DialogueWidget.h"
#include "SetPhraseTask.generated.h"

class UBlackboardComponent;

UCLASS()
class SPROOKJESMOBIEL_API USetPhraseTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	USetPhraseTask();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Player Key", Category = "Input")
	FBlackboardKeySelector m_PlayerKey;

	UPROPERTY(EditAnywhere, DisplayName = "HUD Key", Category = "Input")
	FBlackboardKeySelector m_HUDKey;

	UPROPERTY(EditAnywhere, DisplayName = "Phrase", Category = "Input")
	FString m_Phrase;

	UPROPERTY(EditAnywhere, DisplayName = "Active Side", Category = "Input")
	EActiveDialogueSide m_ActiveSide;

	UPROPERTY(EditAnywhere, DisplayName = "Wait for Input", Category = "Input")
	bool m_WaitForInput;

	//Blackboard reference
	UBlackboardComponent* m_pBlackboard;

	//Helper functions
	EBTNodeResult::Type BindInputEvent(UBehaviorTreeComponent& OwnerComp);

	UFUNCTION()
	void Continue();

	UFUNCTION()
	void ContinueWithSkip();
};