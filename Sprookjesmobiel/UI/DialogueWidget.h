// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/NPC/Base/NPCControllerBase.h"
#include "DialogueWidget.generated.h"

class UTexture2D;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAnswerDispatcher, EAnswer, answer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTypeDispatcher);

UENUM(BlueprintType)
enum class EActiveDialogueSide : uint8
{
	ENone		UMETA(DisplayName = "None"),
	ELeft		UMETA(DisplayName = "Left"),
	ERight		UMETA(DisplayName = "Right")
};

UCLASS()
class SPROOKJESMOBIEL_API UDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UDialogueWidget(const FObjectInitializer& ObjectInitializer);

	void Open();
	void Close();

	void SetPhrase(const FString& phrase, const EActiveDialogueSide activeSide);
	void SetLeftName(const FString& leftName);
	void SetRightName(const FString& rightName);
	void SetLeftSprite(UTexture2D* pSprite);
	void SetRightSprite(UTexture2D* pSprite);
	void SetAnswers(const FString& top, const FString& middle, const FString& bottom);

	FORCEINLINE bool IsTypingText() const
	{
		return m_IsTypingText;
	}

	FORCEINLINE FAnswerDispatcher& GetAnswerDispatcher()
	{
		return m_AnswerDispatcher;
	}

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void EnableBackGround(bool enable);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetPhrase();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowAnimation(bool show);

protected:
	UFUNCTION(BlueprintCallable)
	void SendAnswerEvent(EAnswer answer);

private:
	//Bindings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Phrase", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_Phrase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "LeftName", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_LeftName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "RightName", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_RightName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "LeftSprite", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FSlateBrush m_LeftSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "RightSprite", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FSlateBrush m_RightSprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonTopText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_ButtonTopText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonMiddleText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_ButtonMiddleText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonBottomText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_ButtonBottomText;

	//Visibility
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "DialogueVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_DialogueVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "NameBorderLeftVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_NameBorderLeftVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "NameBorderRightVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_NameBorderRightVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "SpriteLeftVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_SpriteLeftVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "SpriteRightVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_SpriteRightVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonTopVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_ButtonTopVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonMiddleVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_ButtonMiddleVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ButtonBottomVisibility", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	ESlateVisibility m_ButtonBottomVisibility;

	//Other variables
	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "ActiveDialogueSide", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	EActiveDialogueSide m_ActiveSide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "TypeText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_TypeText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "IsTypingText", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	bool m_IsTypingText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, DisplayName = "TypeDelay", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	float m_TypeDelay;

	//Event dispatchers
	UPROPERTY(BlueprintAssignable, DisplayName = "AnswerDispatcher", Category = "EventDispatchers")
	FAnswerDispatcher m_AnswerDispatcher;

	UPROPERTY(BlueprintAssignable, DisplayName = "TypeDispatcher", Category = "EventDispatchers")
	FTypeDispatcher m_TypeDispatcher;
};
