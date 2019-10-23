// Fill out your copyright notice in the Description page of Project Settings.

#include "LogTask.h"

EBTNodeResult::Type ULogTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *m_Message);

	return EBTNodeResult::Type::Succeeded;
}