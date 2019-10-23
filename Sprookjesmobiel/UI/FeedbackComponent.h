// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BillboardComponent.h"
#include "FeedbackComponent.generated.h"

class UTexture2D;
class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API UFeedbackComponent : public UBillboardComponent
{
	GENERATED_BODY()
	
public:
	void ShowRequiredItem(TSubclassOf<UBaseItem> pItemClass);
	void ShowError();

private:
	UPROPERTY(EditAnywhere, DisplayName = "Error Sprite", Category = "UI")
	UTexture2D* m_pErrorSprite;
};