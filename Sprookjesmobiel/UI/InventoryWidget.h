// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

class UBaseItem;
class UImage;

UCLASS()
class SPROOKJESMOBIEL_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool AddItem(TSubclassOf<UBaseItem> itemClass);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(TSubclassOf<UBaseItem> itemClass);
	bool RemoveItem(FName name);

	UFUNCTION(BlueprintCallable)
	bool Contains(TSubclassOf<UBaseItem> itemClass,int Quantity);
	bool Contains(TSubclassOf<UBaseItem> itemClass);
	bool Contains(FName name);

	UFUNCTION(BlueprintCallable)
	void Empty();

	void ClearSelectedItem();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsSlotFilled(int slotNr);

	UFUNCTION(BlueprintPure)
	FORCEINLINE UBaseItem* GetSelectedItem()
	{
		if (m_SelectedIdx < 0 || m_SelectedIdx >= m_pItems.Num())
			return nullptr;

		return m_pItems[m_SelectedIdx];
	}

	UFUNCTION(BlueprintImplementableEvent)
	void Blink(int idx, float speed);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FadeIn(float time);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FadeOut(float time);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateImage(int idx, UTexture2D* pTexture);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void RefreshImage(int idx);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	TArray<UTexture2D*> m_pSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", Meta = (AllowPrivateAccess = "true"))
	TArray<UBaseItem*> m_pItems;

	int m_SelectedIdx = -1;
	
	UFUNCTION(BlueprintCallable)
	void AddSlot(UTexture2D* newSlot);

	UFUNCTION(BlueprintPure)
	FORCEINLINE int GetSelectedIdx()
	{
		return m_SelectedIdx;
	}

	UFUNCTION(BlueprintCallable)
	void SetSelectedIdx(int idx);

	//void UpdateSlots();

	

	/*UFUNCTION(BlueprintCallable)
	void Blink_Implementation(int idx);*/
};