// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CanvasPanel.h"
#include "HintWidget.generated.h"

/**
 * 
 */

UCLASS()
class SPROOKJESMOBIEL_API UHintWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetNewHint(FString index,int32 Skiphints=-1);
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
private:
	struct HintSkipRange {
		int32 HintIndex;
		int32 MinimumHintIndex;
	};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "HintText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_Hint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Timer for hint to appear", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	float m_HintTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Current Hint Timer", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	float m_CurrentTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "CanvasEnabled", Category = "Default", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_CanvasVisibility;
	int32 m_LastHint;
	TArray<HintSkipRange> m_Hints;
};
