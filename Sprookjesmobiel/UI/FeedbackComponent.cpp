// Fill out your copyright notice in the Description page of Project Settings.

#include "FeedbackComponent.h"
#include "Gameplay/Items/BaseItem.h"

void UFeedbackComponent::ShowRequiredItem(TSubclassOf<UBaseItem> pItemClass)
{
	if (pItemClass)
	{
		UBaseItem* pItem = Cast<UBaseItem>(pItemClass->GetDefaultObject());
		SetSprite(pItem->GetThumbnail());
	}
	else
		SetSprite(nullptr);
}

void UFeedbackComponent::ShowError()
{
	SetSprite(m_pErrorSprite);
}