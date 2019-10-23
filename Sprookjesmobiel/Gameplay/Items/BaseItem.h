// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseItem.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SPROOKJESMOBIEL_API UBaseItem : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure)
	FORCEINLINE FName GetName()
	{
		return m_Name;
	}
	UFUNCTION(BlueprintPure)
	FORCEINLINE UTexture2D* GetThumbnail()
	{
		return m_pThumbnail;
	}

private:
	UPROPERTY(EditAnywhere, Category = "Item Variables")
	FName m_Name;

	UPROPERTY(EditAnywhere, Category = "Item Variables")
	class UTexture2D* m_pThumbnail;
};
