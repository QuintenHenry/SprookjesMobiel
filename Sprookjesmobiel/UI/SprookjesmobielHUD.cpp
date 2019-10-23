// Fill out your copyright notice in the Description page of Project Settings.

#include "SprookjesmobielHUD.h"
#include "DialogueWidget.h"
#include "InventoryWidget.h"
#include "HintWidget.h"
#include "InfoObjectsWidget.h"
#include "LoadingScreenWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SprookjesmobielGameInstance.h"

ASprookjesmobielHUD::ASprookjesmobielHUD()
{
	//Set default values
	m_pDialogueWidgetClass = nullptr;
	m_pInventoryWidgetClass = nullptr;
	m_pDialogueWidget = nullptr;
	m_pHintWidgetClass = nullptr;
}

void ASprookjesmobielHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	CreateDialogueWidget(pController);
	CreateInventoryWidget(pController);
	CreateHintWidget(pController);
	CreateInfoWidget(pController);
	CreateLoadingScreenWidget(pController);
}

void ASprookjesmobielHUD::ActivateLoadingScreen()
{
	m_pLoadingScreenWidget->Activate();
}

void ASprookjesmobielHUD::FadeIn(float time)
{
	m_pLoadingScreenWidget->FadeIn(time);
}

void ASprookjesmobielHUD::FadeOut(float time)
{
	m_pLoadingScreenWidget->FadeOut(time);
}

void ASprookjesmobielHUD::CreateDialogueWidget(APlayerController* pController)
{
	if (!m_pDialogueWidgetClass) 
	{
		UE_LOG(LogTemp, Warning, TEXT("ASprookjesmobielHUD::CreateDialogueWidget - Widget class not specified"));
		return;
	}

	m_pDialogueWidget = CreateWidget<UDialogueWidget>(pController, m_pDialogueWidgetClass);
	if (m_pDialogueWidget)
		m_pDialogueWidget->AddToViewport();
}

void ASprookjesmobielHUD::CreateInventoryWidget(APlayerController* pController)
{
	//Check if inventory exists in GameInstance
	USprookjesmobielGameInstance* pGameInstance = Cast<USprookjesmobielGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (pGameInstance)
	{
		if (!pGameInstance->pInventory)
		{
			if(!m_pInventoryWidgetClass)
			{
				UE_LOG(LogTemp, Warning, TEXT("ASprookjesmobielHUD::CreateInventoryWidget - Widget class not specified"));
				return;
			}

			m_pInventoryWidget = CreateWidget<UInventoryWidget>(pController, m_pInventoryWidgetClass);
			if (m_pInventoryWidget)
			{
				m_pInventoryWidget->AddToViewport();
				pGameInstance->pInventory = m_pInventoryWidget;
			}
		}
		else
			pGameInstance->pInventory->AddToViewport();
	}	
}

void ASprookjesmobielHUD::CreateHintWidget(APlayerController* pController)
{
	if (!m_pHintWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASprookjesmobielHUD::CreateHintWidget - Widget class not specified"));
		return;
	}

	m_pHintWidget = CreateWidget<UHintWidget>(pController, m_pHintWidgetClass);
	if (m_pHintWidget)
		m_pHintWidget->AddToViewport();
}

void ASprookjesmobielHUD::CreateInfoWidget(APlayerController* pController)
{
	if (!m_pInfoWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASprookjesmobielHUD::CreateInfoWidget - Widget class not specified"));
		return;
	}

	m_pInfoWidget = CreateWidget<UInfoObjectsWidget>(pController, m_pInfoWidgetClass);
	if (m_pInfoWidget)
		m_pInfoWidget->AddToViewport();
}

void ASprookjesmobielHUD::CreateLoadingScreenWidget(APlayerController* pController)
{
	if (!m_pLoadingScreenClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("ASprookjesmobielHUD::CreateLoadingScreenWidget - Widget class not specified"));
		return;
	}

	m_pLoadingScreenWidget = CreateWidget<ULoadingScreenWidget>(pController, m_pLoadingScreenClass);
	if (m_pLoadingScreenWidget)
		m_pLoadingScreenWidget->AddToViewport();
}