// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueWidget.h"
#include "Engine/Texture2D.h"

UDialogueWidget::UDialogueWidget(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	//Set default values
	m_Phrase = "Phrase";
	m_LeftName = "Left Name";
	m_RightName = "Right Name";
	m_LeftSprite = FSlateBrush();
	m_RightSprite = FSlateBrush();
	m_ButtonTopText = "Top Button";
	m_ButtonMiddleText = "Middle Button";
	m_ButtonBottomText = "Bottom Button";

	m_DialogueVisibility = ESlateVisibility::Hidden;
	m_NameBorderLeftVisibility = ESlateVisibility::Visible;
	m_NameBorderRightVisibility = ESlateVisibility::Visible;
	m_SpriteLeftVisibility = ESlateVisibility::Visible;
	m_SpriteRightVisibility = ESlateVisibility::Visible;
	m_ButtonTopVisibility = ESlateVisibility::Hidden;
	m_ButtonMiddleVisibility = ESlateVisibility::Hidden;
	m_ButtonBottomVisibility = ESlateVisibility::Hidden;

	m_ActiveSide = EActiveDialogueSide::ENone;
	m_IsTypingText = false;
	m_TypeDelay = 0.01f;
}

void UDialogueWidget::Open()
{
	m_DialogueVisibility = ESlateVisibility::SelfHitTestInvisible;
	SetIsEnabled(true);

	ShowAnimation(true);
}

void UDialogueWidget::Close()
{
	ShowAnimation(false);
}

void UDialogueWidget::SetPhrase(const FString& phrase, const EActiveDialogueSide activeSide)
{
	m_Phrase = phrase;
	m_ActiveSide = activeSide;
	m_IsTypingText = true;
	m_TypeText = FString();
	ResetPhrase();
	m_TypeDispatcher.Broadcast();
}

void UDialogueWidget::SetLeftName(const FString& leftName)
{
	m_LeftName = leftName;
	m_NameBorderLeftVisibility = (leftName.Len() > 0) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
}

void UDialogueWidget::SetRightName(const FString& rightName)
{
	m_RightName = rightName;
	m_NameBorderRightVisibility = (rightName.Len() > 0) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
}

void UDialogueWidget::SetLeftSprite(UTexture2D* pSprite)
{
	m_LeftSprite.SetResourceObject(pSprite);
	m_LeftSprite.ImageSize = FVector2D(512.0f, 512.0f);

	m_SpriteLeftVisibility = (pSprite) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
}

void UDialogueWidget::SetRightSprite(UTexture2D* pSprite)
{
	m_RightSprite.SetResourceObject(pSprite);
	m_RightSprite.ImageSize = FVector2D(512.0f, 512.0f);

	m_SpriteRightVisibility = (pSprite) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
}

void UDialogueWidget::SetAnswers(const FString& top, const FString& middle, const FString& bottom)
{
	m_ButtonTopText = top;
	m_ButtonTopVisibility = (top.Len() > 0) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;

	m_ButtonMiddleText = middle;
	m_ButtonMiddleVisibility = (middle.Len() > 0) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;

	m_ButtonBottomText = bottom;
	m_ButtonBottomVisibility = (bottom.Len() > 0) ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
}

void UDialogueWidget::SendAnswerEvent(EAnswer answer)
{
	m_AnswerDispatcher.Broadcast(answer);
}