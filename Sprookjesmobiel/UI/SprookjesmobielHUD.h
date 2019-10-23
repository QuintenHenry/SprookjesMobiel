// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SprookjesmobielHUD.generated.h"

class UUserWidget;
class UDialogueWidget;
class UInventoryWidget;
class UHintWidget;
class UInfoObjectsWidget;
class ULoadingScreenWidget;
class APlayerController;

UCLASS()
class SPROOKJESMOBIEL_API ASprookjesmobielHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ASprookjesmobielHUD();

	UFUNCTION(BlueprintPure)
	FORCEINLINE UDialogueWidget* GetDialogueWidget()
	{
		return m_pDialogueWidget;
	};

	FORCEINLINE UInventoryWidget* GetInventoryWidget()
	{
		return m_pInventoryWidget;
	};
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UHintWidget* GetHintWidget() 
	{
		return m_pHintWidget;
	};
	UFUNCTION(BlueprintCallable)
	FORCEINLINE UInfoObjectsWidget* GetInfoWidget()
	{
		return m_pInfoWidget;
	}

	UFUNCTION(BlueprintCallable)
	void ActivateLoadingScreen();

	UFUNCTION(BlueprintCallable)
	void FadeIn(float time);

	UFUNCTION(BlueprintCallable)
	void FadeOut(float time);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, DisplayName = "Dialogue Widget", Category = "UI")
	TSubclassOf<UUserWidget> m_pDialogueWidgetClass;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Inventory Widget", Category = "UI")
	TSubclassOf<UUserWidget> m_pInventoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Hint Widget", Category = "UI")
	TSubclassOf<UUserWidget> m_pHintWidgetClass;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Info Widget", Category = "UI")
	TSubclassOf<UUserWidget> m_pInfoWidgetClass;

	UPROPERTY(EditDefaultsOnly, DisplayName = "Loading Screen", Category = "UI")
	TSubclassOf<UUserWidget> m_pLoadingScreenClass;

	//Variables
	UDialogueWidget* m_pDialogueWidget;
	UInventoryWidget* m_pInventoryWidget;
	UHintWidget* m_pHintWidget;
	UInfoObjectsWidget* m_pInfoWidget;
	ULoadingScreenWidget* m_pLoadingScreenWidget;

	//Helper functions
	void CreateDialogueWidget(APlayerController* pController);
	void CreateInventoryWidget(APlayerController* pController);
	void CreateHintWidget(APlayerController* pController);
	void CreateInfoWidget(APlayerController* pController);
	void CreateLoadingScreenWidget(APlayerController* pController);
};