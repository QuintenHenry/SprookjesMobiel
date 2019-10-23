// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/Player/PlayerCharacter.h"
#include "LoadingScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class SPROOKJESMOBIEL_API ULoadingScreenWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setter")
	void Activate();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FadeIn(float time);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FadeOut(float time);
};
