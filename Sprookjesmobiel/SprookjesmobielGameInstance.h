// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SprookjesmobielGameInstance.generated.h"

class UInventoryWidget;

UCLASS()
class SPROOKJESMOBIEL_API USprookjesmobielGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	USprookjesmobielGameInstance(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Inventory", Category = "GameInstance")
	UInventoryWidget* pInventory;
};