// Fill out your copyright notice in the Description page of Project Settings.

#include "AnswerDecorator.h"
#include "BehaviorTree/BlackboardComponent.h"

bool UAnswerDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	UBlackboardComponent* pBlackboard = OwnerComp.GetBlackboardComponent();

	if (pBlackboard)
	{
		EAnswer answer = static_cast<EAnswer>(pBlackboard->GetValueAsEnum(m_AnswerKey.SelectedKeyName));

		if (answer == EAnswer::ENone)
		{
			UE_LOG(LogTemp, Warning, TEXT("AnswerDecorator::CalculateRawConditionValue - Answer is None"));
			return false;
		}

		return (answer == m_Answer);
	}

	UE_LOG(LogTemp, Warning, TEXT("AnswerDecorator::CalculateRawConditionValue - Could not get blackboard component"));
	return false;
}