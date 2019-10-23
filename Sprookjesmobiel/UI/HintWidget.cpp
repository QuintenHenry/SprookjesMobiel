// Fill out your copyright notice in the Description page of Project Settings.

#include "HintWidget.h"
#include "Kismet/KismetTextLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"
void UHintWidget::SetNewHint(FString index, int32 Skiphints) {

	if (index == "-1")
	{
		m_Hint = "";
		m_CurrentTimer = 0.0f;
	}
	else
	{

		int32 currenthint = FCString::Atoi(*index);


		//add if this hint can skip others
		if (Skiphints != -1)
		{
			HintSkipRange hint;
			hint.HintIndex = currenthint;
			hint.MinimumHintIndex = Skiphints;
			m_Hints.Add(hint);
		}

		if (!(currenthint - 1 == m_LastHint) && (Skiphints!=m_LastHint))
			return;

		//loop through skippable hints
		for (HintSkipRange hint : m_Hints)
		{
			if (hint.MinimumHintIndex <= currenthint && hint.HintIndex>currenthint) {
				currenthint = hint.HintIndex;
				index = FString::FromInt(currenthint);
			}
		}


		

		m_LastHint = currenthint;
		FString mapname = UGameplayStatics::GetCurrentLevelName(GetWorld());
		FString tablename = "/Game/Gameplay/Data/HintTable" + mapname + ".HintTable" + mapname;
		FText out;
		out = FText::FromStringTable(FName(*tablename), index);
		/*if (UKismetTextLibrary::FindTextInLocalizationTable("HintTable", index, out))
			m_Hint = out.ToString();
		else
			m_Hint = index;*/

		m_Hint = out.ToString();
		m_CurrentTimer = 0.0f;
	}
}
void UHintWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {


	Super::NativeTick(MyGeometry, InDeltaTime);


	ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
	if (m_Hint!="" && !hud->GetDialogueWidget()->bIsEnabled)
	m_CurrentTimer += InDeltaTime;
	
	if (m_CurrentTimer <= m_HintTimer)
		m_CanvasVisibility = ESlateVisibility::Hidden;
	else
		m_CanvasVisibility = ESlateVisibility::SelfHitTestInvisible;
}


