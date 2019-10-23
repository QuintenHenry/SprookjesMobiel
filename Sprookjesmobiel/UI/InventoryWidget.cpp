// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryWidget.h"
#include "Gameplay/Items/BaseItem.h"
#include "Engine/Texture2D.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "SprookjesmobielGameModeBase.h"
#include "Managers/SoundManager.h"

void UInventoryWidget::AddSlot(UTexture2D* slot)
{
	//m_pSlots.Push(slot);

	UBaseItem* tempItem = NewObject<UBaseItem>(this, UBaseItem::StaticClass());
	m_pItems.Push(tempItem);
	//UpdateSlots();
}

bool UInventoryWidget::AddItem(TSubclassOf<UBaseItem> itemClass)
{
	UBaseItem* pItem = NewObject<UBaseItem>(this, itemClass);

	for(int i = 0; i < m_pItems.Num(); ++i)
	{
		if(m_pItems[i]->GetName() == "")
		{
			//Play sound
			ASprookjesmobielGameModeBase* gameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			if(!gameMode)
			{
				UE_LOG(LogTemp, Warning, TEXT("GameMode not found"));
				return false;
			}

			gameMode->GetSoundManager()->PlaySound("ItemGet");

			Blink(i, 1.0f);

			m_pItems[i] = pItem;
			UpdateImage(i, itemClass.GetDefaultObject()->GetThumbnail());
			//UpdateSlots();

			return true;
		}
	}
	return false;
}

bool UInventoryWidget::RemoveItem(TSubclassOf<UBaseItem> itemClass)
{
	for (int32 i = 0; i < m_pItems.Num(); ++i)
	{
		if (m_pItems[i]->IsA(itemClass))
		{
			m_pItems[i] = NewObject<UBaseItem>();
			UpdateImage(i, nullptr);
			//UpdateSlots();
			return true;
		}
	}

	return false;
}

bool UInventoryWidget::RemoveItem(FName name)
{
	for(int i = 0; i < m_pItems.Num(); ++i)
	{
		if(m_pItems[i]->GetName() == name)
		{
			m_pItems[i] = NewObject<UBaseItem>();
			UpdateImage(i, nullptr);
			return true;
		}
	}

	return false;
}

bool UInventoryWidget::Contains(TSubclassOf<UBaseItem> itemClass,int Quantity)
{
	int counter = 0;
	for (int32 i = 0; i < m_pItems.Num(); ++i)
	{
		if (m_pItems[i]->IsA(itemClass))
			counter++;
	}
	return (counter >= Quantity);
}

bool UInventoryWidget::Contains(TSubclassOf<UBaseItem> itemClass)
{
	for (int32 i = 0; i < m_pItems.Num(); ++i)
	{
		if (m_pItems[i]->IsA(itemClass))
			return true;
	}
	return false;
}

bool UInventoryWidget::Contains(FName name)
{
	for(int i = 0; i < m_pItems.Num(); ++i)
	{
		if(m_pItems[i]->GetName() == name)
			return true;
	}
	return false;
}

void UInventoryWidget::Empty()
{
	for(int i = 0; i < m_pItems.Num(); ++i)
	{
		m_pItems[i] = NewObject<UBaseItem>();
		UpdateImage(i, nullptr);
	}
	//UpdateSlots();
}

void UInventoryWidget::ClearSelectedItem()
{
	m_SelectedIdx = -1;
}

/*void UInventoryWidget::UpdateSlots()
{
	for(int i = 0; i < m_pSlots.Num(); ++i)
	{
		//if(i >= m_pItems.Num()) return;
		//m_pSlots[i]->SetBrushFromTexture(m_pItems[i]->GetThumbnail());
		m_pSlots[i] = m_pItems[i]->GetThumbnail();
	}
}*/

bool UInventoryWidget::IsSlotFilled(int slotNr)
{
	if (m_pItems[slotNr])
	{
		if(m_pItems[slotNr]->GetName() != "")
			return true;
	}

	return false;
}

void UInventoryWidget::SetSelectedIdx(int idx)
{
	m_SelectedIdx = idx;
}

