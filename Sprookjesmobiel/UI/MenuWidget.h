// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Gameplay/Camera/MenuCamera.h"
#include "Button.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API UMenuWidget : public UUserWidget
{
	GENERATED_BODY()
private:
	UFUNCTION(BlueprintCallable)
	void SetOptionsMenu();
	UFUNCTION(BlueprintCallable)
	void SetMainMenu();
	UFUNCTION(BlueprintCallable)
	void SetHelpMenu();
	UFUNCTION(BlueprintCallable)
	void SetGraphicSettings(const int32 AntiAliasing, const int32 Effects, const int32 PostProcess,
			const int32 Resolution, const int32 Shadow, const int32 Texture, const float ViewDistance);
};
