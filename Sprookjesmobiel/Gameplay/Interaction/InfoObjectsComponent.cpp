// Fill out your copyright notice in the Description page of Project Settings.

#include "InfoObjectsComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/InfoObjectsWidget.h"

UInfoObjectsComponent::UInfoObjectsComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	m_pInfoWidget = nullptr;
	m_pActiveInfoObject = nullptr;
}

void UInfoObjectsComponent::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* pController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (pController)
	{
		ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(pController->GetHUD());
		m_pInfoWidget = pHUD->GetInfoWidget();

		if (m_pInfoWidget)
			m_pInfoWidget->SetMax(m_FoundObjects.Num());
	}
}

bool UInfoObjectsComponent::Find(AInfoActor* pInfoObject)
{
	TSubclassOf<AInfoActor> findClass = pInfoObject->GetClass();
	bool* pValue = m_FoundObjects.Find(findClass);

	if (pValue)
	{
		if (*pValue == false)
		{
			*pValue = true;
			return true;
		}
	}
	return false;
}

void UInfoObjectsComponent::UpdateUI()
{
	if (m_pInfoWidget)
	{
		m_pInfoWidget->Update();
		m_pInfoWidget->Show();
	}
}