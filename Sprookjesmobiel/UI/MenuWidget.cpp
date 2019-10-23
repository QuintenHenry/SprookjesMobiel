// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Gameplay/Camera/MenuCamera.h"
#include "Engine.h"
void UMenuWidget::SetMainMenu() {
	Cast<AMenuCamera>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn())->SetCameraTarget(AMenuCamera::CurrentMenu::Main);
}
void UMenuWidget::SetGraphicSettings(const int32 AntiAliasing, const int32 Effects, const int32 PostProcess, const int32 Resolution, const int32 Shadow, const int32 Texture, const float ViewDistance)
{
	UE_LOG(LogTemp, Warning, TEXT("ChangedGraphicSettings"));
	UGameUserSettings* Settings = nullptr;
	if (GEngine != nullptr)
	{
		Settings = GEngine->GameUserSettings;
	}
	if (Settings)
	{
		Settings->ScalabilityQuality.AntiAliasingQuality = AntiAliasing;
		Settings->ScalabilityQuality.EffectsQuality = Effects;
		Settings->ScalabilityQuality.PostProcessQuality = PostProcess;
		Settings->ScalabilityQuality.ResolutionQuality = Resolution;
		Settings->ScalabilityQuality.ShadowQuality = Shadow;
		Settings->ScalabilityQuality.TextureQuality = Texture;
		Settings->ScalabilityQuality.ViewDistanceQuality = ViewDistance;

		Settings->ConfirmVideoMode();
		Settings->ApplyNonResolutionSettings();
		Settings->SaveSettings();
	}
}
void UMenuWidget::SetOptionsMenu() {

	Cast<AMenuCamera>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn())->SetCameraTarget(AMenuCamera::CurrentMenu::Options);
}
void UMenuWidget::SetHelpMenu() {

	Cast<AMenuCamera>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn())->SetCameraTarget(AMenuCamera::CurrentMenu::Help);
}