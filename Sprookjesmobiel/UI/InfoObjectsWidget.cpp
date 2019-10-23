// Fill out your copyright notice in the Description page of Project Settings.

#include "InfoObjectsWidget.h"

UInfoObjectsWidget::UInfoObjectsWidget(const FObjectInitializer& ObjectInitializer)
	: UUserWidget(ObjectInitializer)
{
	m_ObjectsFoundString = FString("0");
	m_MaxObjectsString = FString("0");
	m_ObjectsFound = 0;
	m_MaxObjects = 0;
}

void UInfoObjectsWidget::Show_Implementation()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UInfoObjectsWidget::Update()
{
	++m_ObjectsFound;
	m_ObjectsFoundString = FString::FromInt(m_ObjectsFound);
}

void UInfoObjectsWidget::SetMax(int32 newMax)
{
	m_MaxObjects = newMax;
	m_MaxObjectsString = FString::FromInt(newMax);
}