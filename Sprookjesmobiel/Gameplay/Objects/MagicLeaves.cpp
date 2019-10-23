// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicLeaves.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Characters/Player/MainPlayerController.h"
#include "UI/InventoryWidget.h"
#include <EngineGlobals.h>
#include "Kismet/GameplayStatics.h"
#include "Sprookjesmobiel/UI/SprookjesmobielHUD.h"
#include "UI/HintWidget.h"
#include "SprookjesmobielGameModeBase.h"
#include "Characters/Player/MainPlayerController.h"
 #include <Runtime/Engine/Classes/Engine/Engine.h>
void AMagicLeaves::Interact(APlayerCharacter* pPlayer) {

	if (!m_CanShake)
	{
		UInventoryWidget *inventory = pPlayer->GetInventory();
		//inventory->AddItem(m_MagicLeavesItem);

		AMainPlayerController* controller = Cast<AMainPlayerController>(pPlayer->GetController());

		if (controller)
			controller->SetEnableMove(false);

		ASprookjesmobielGameModeBase* gamemode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		if (!gamemode) return;
		FVector offset{ -400.0f,0.0f,200.0f };
		gamemode->GetInputManager()->SetShakingIconPosition(GetActorLocation() + offset);
		m_CanShake = true;
	}
}

void AMagicLeaves::Tick(float deltaTime) {
	Super::Tick(deltaTime);

	
	if (m_HasTakenLeaves)
		return;
	if (!m_CanShake)
		return;


	ASprookjesmobielGameModeBase* gamemode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!gamemode) return;

	//Shake
	if (gamemode->GetInputManager()->GetIsShaking())
	{

		//set hint
		ASprookjesmobielHUD* hud = Cast<ASprookjesmobielHUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD());
		hud->GetHintWidget()->SetNewHint("3");

		AMainPlayerController *playercontroller = Cast<AMainPlayerController>(GetWorld()->GetFirstPlayerController());
		playercontroller->SetEnableMove(true);
		APlayerCharacter* player = Cast<APlayerCharacter>(playercontroller->GetPawn());
		UInventoryWidget *inventory = player->GetInventory();
		inventory->AddItem(m_MagicLeavesItem);
		m_HasTakenLeaves = true;
		gamemode->GetInputManager()->HideShakeIcon();
	}


}