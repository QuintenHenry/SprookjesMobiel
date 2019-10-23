// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Runtime/NavigationSystem/Public/AbstractNavData.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Gameplay/Camera/MainCameraActor.h"
#include "Gameplay/Interaction/Interactable.h"
#include "SprookjesmobielGameModeBase.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "UI/InventoryWidget.h"
#include "Managers/ParticleManager.h"
#include "Camera/CameraComponent.h"
#include "Gameplay/Objects/DateTreeActor.h"
#include "UI/SprookjesmobielHUD.h"
#include "UI/DialogueWidget.h"
#include "Characters/NPC/Laila/LailaCairoPawn.h"
#include "Gameplay/Interaction/InfoObjectsComponent.h"

#include <EngineGlobals.h>
 #include <Runtime/Engine/Classes/Engine/Engine.h>

AMainPlayerController::AMainPlayerController()
{
	m_CanMove = true;
	m_CanSwipe = true;
}

void AMainPlayerController::SetupInputComponent()
{
	//Setup parent input
	Super::SetupInputComponent();

	//Setup inputs for mouseclicks
	this->InputComponent->BindAction("LeftClick", IE_Pressed, this, &AMainPlayerController::SetMouseDown);
	this->InputComponent->BindAction("LeftClick", IE_Released, this, &AMainPlayerController::SetMouseUp);
	this->InputComponent->BindAction("Ignore", IE_Pressed, this, &AMainPlayerController::Ignore);
	this->InputComponent->BindAction("Ignore", IE_Released, this, &AMainPlayerController::Ignore);
}

void AMainPlayerController::Tick(float deltaTime)
{
	//Parent tick
	Super::Tick(deltaTime);

	ProcessMouseClicks(deltaTime);
	if (GetCharacter())
	SpeedupOutOfScreen();


	/*DrawDebugLine(GetWorld(), FVector(m_SwipeX, -10000.0f, 200.0f), FVector(m_SwipeX, 10000.0f, 200.0f), FColor(1.0f, 0.0f, 0.0f), true);*/
}
void AMainPlayerController::Possess(APawn* InPawn) {
	Super::Possess(InPawn);

	//Set player movement variables
	ACharacter* pCharacter = GetCharacter();
	if(pCharacter)
	{
		UCharacterMovementComponent* moveComp = Cast<UCharacterMovementComponent>(pCharacter->GetMovementComponent());
		moveComp->MaxWalkSpeed = m_PlayerSpeed;
		moveComp->MaxAcceleration = m_PlayerAcc;
		moveComp->SetFixedBrakingDistance(m_PlayerBreakDist);
	}
	
}

void AMainPlayerController::BeginPlay()
{
	//Parent init
	Super::BeginPlay();

	//Set mouse defaults
	bShowMouseCursor = true;
	m_IsMouseDown = false;
	m_IsDragging = false;
	m_PreviousMousePos = {-1, -1};
}

//Set mouse to down
void AMainPlayerController::SetMouseDown()
{
	m_IsMouseDown = true;
}

//Unset mouse down
void AMainPlayerController::SetMouseUp()
{
	m_MouseHoldTimer = 0.0f;
	m_IsMouseDown = false;
}

void AMainPlayerController::ProcessMouseClicks(float deltaTime)
{
	//If the mouse button is down
	if(m_IsMouseDown)
	{
		if(!m_IsDragging)
		{
			m_MouseHoldTimer += deltaTime;
			if(m_MouseHoldTimer >= m_MouseHoldTime)
			{
				m_IsMouseDown = false;
				m_MouseHoldTimer = 0.0f;
				OnClick();
			}
		}

		//Get current mouse position
		FVector2D currentMousePos;
		GetMousePosition(currentMousePos.X, currentMousePos.Y);

		//If there is no previous position set yet, set it to the current
		if(m_PreviousMousePos == FVector2D{-1,-1})
			m_PreviousMousePos = currentMousePos;

		//If the mouse has moved
		if((currentMousePos - m_PreviousMousePos).Size() > 10.0f)
		{
			//The player is now dragging
			m_IsDragging = true;

			//All drag functionality in here
			OnDrag(deltaTime, currentMousePos);

			//Set the previous mouse position for the next frame
			m_PreviousMousePos = currentMousePos;
		}
	}
	//If the mouse button is not down and the previous mouse position has been set
	else if(m_PreviousMousePos != FVector2D{-1,-1})
	{
		//If the user is not dragging, call click
		if(!m_IsDragging)
			//All click functionality in here
			OnClick();

		//Reset the previous mouse position to non-existent and set dragging to false
		m_PreviousMousePos = {-1, -1};
		m_IsDragging = false;
	}
}

void AMainPlayerController::OnDrag(float deltaTime, FVector2D currentMousePos)
{
	if(!m_CanSwipe) return;		//TESTING

	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(GetCharacter());
	if (!pCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MainPlayerController::OnDrag - Could not get Character"));
		return;
	}

	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!pGameMode)
	{
		UE_LOG(LogTemp, Error, TEXT("AMainPlayerController::OnDrag - Could not retrieve GameMode"));
		return;
	}

	pGameMode->GetParticleManager()->StopSwipeParticle();

	//Ignore if in dialogue
	ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(GetHUD());
	UDialogueWidget* pDialogueWidget = pHUD->GetDialogueWidget();
	if (pDialogueWidget->GetIsEnabled())
		return;

	//Move to camera
	AMainCameraActor* pCamera = pCharacter->GetCamera();
	if (pCamera)
	{
		pCamera->SetForce(currentMousePos.X - m_PreviousMousePos.X);
		pCharacter->SetInteractable(nullptr);
	}
}

void AMainPlayerController::OnClick()
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(GetCharacter());
	if (!pCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MainPlayerController::OnClick - Could not get Character"));
		return;
	}

	AMainCameraActor* pCamera = pCharacter->GetCamera();
	if (pCamera)
	{
		pCamera->SetForce(0.0f);
	}

	ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(GetHUD());
	UDialogueWidget* pDialogueWidget = pHUD->GetDialogueWidget();

	//if (pCharacter->GetActiveNPC() || (!m_CanMove && !m_CanSwipe))
	if (pDialogueWidget->GetIsEnabled() || (!m_CanMove && !m_CanSwipe))
		DialogueContinue();
	else
		InteractWithWorld();
}

void AMainPlayerController::InteractWithWorld()
{
	FHitResult hit;

	if (GetHitPoint(hit))
	{
		ProcessHit(hit);
	}
}
	
void AMainPlayerController::DialogueContinue()
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(GetCharacter());
	if (!pCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MainPlayerController::DialogueContinue - Could not get Character"));
		return;
	}

	if (pCharacter->GetActiveNPC()  || (!m_CanMove && !m_CanSwipe))
		m_InputDispatcher.Broadcast();
	else
	{
		//Reading info object
		AInfoActor* pInfoObject = pCharacter->GetActiveInfoObject();
		if (pInfoObject)
		{
			ASprookjesmobielHUD* pHUD = Cast<ASprookjesmobielHUD>(GetHUD());
			UDialogueWidget* pDialogueWidget = pHUD->GetDialogueWidget();

			FString info = pInfoObject->GetInfo();
			if (!info.IsEmpty())
				pDialogueWidget->SetPhrase(info, EActiveDialogueSide::ENone);
			else
			{
				pDialogueWidget->SetPhrase(FString(), EActiveDialogueSide::ENone);
				pDialogueWidget->Close();

				SetViewTargetWithBlend(pCharacter->GetCamera(), 1.0f);
				pCharacter->SetActorHiddenInGame(false);
				pCharacter->SetInfoActor(nullptr);
			}
		}		
	}
}

void AMainPlayerController::MovePlayerToCamera(float cameraY)
{
	if (!m_CanMove) return;
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(GetCharacter());
	if (!pCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("MainPlayerController::MovePlayerToCamera - Could not get Character"));
		return;
	}

	//Get the dist between the camera and the player on the y axis, if this is bigger than a certain amount
	float yDiff = FMath::Abs(pCharacter->GetActorLocation().Y - cameraY);

	if(yDiff > m_FreemoveDistance)
	{
		//Point up to start the line trace
		FVector start = FVector(m_SwipeX, cameraY, 10000.0f);

		//Point down to end the line trace
		FVector end = FVector(m_SwipeX, cameraY, -10000.0f);

		//Linetrace and move to the hitlocation
		FHitResult hit;
		if(GetWorld()->LineTraceSingleByChannel(hit, start, end, ECollisionChannel::ECC_Visibility))
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, hit.Location);
	}
}

void AMainPlayerController::SpawnSparkleParticle(const FVector& worldPos)
{
	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	AParticleManager* pParticleManager = pGameMode->GetParticleManager();

	if (pParticleManager)
		pParticleManager->SpawnParticle("Sparkles1", worldPos);
}
void AMainPlayerController::SpawnNavParticle(const FVector& worldPos)
{
	ASprookjesmobielGameModeBase* pGameMode = Cast<ASprookjesmobielGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	AParticleManager* pParticleManager = pGameMode->GetParticleManager();

	if (pParticleManager)
		pParticleManager->SpawnParticle("Navigation", worldPos);
}

void AMainPlayerController::SpeedupOutOfScreen()
{
	if(!GetCharacter()) return;

	AMainCameraActor* pCamera = Cast<APlayerCharacter>(GetCharacter())->GetCamera();
	UCameraComponent* pCamComp = Cast<UCameraComponent>(pCamera->GetComponentByClass(UCameraComponent::StaticClass()));

	FVector playerPos = GetCharacter()->GetActorLocation();
	FVector cameraPos = pCamComp->GetComponentLocation();

	FVector camMiddlePos = FVector(playerPos.X, cameraPos.Y, playerPos.Z);

	float camToMiddle = FVector::DistSquared(cameraPos, camMiddlePos);
	float camToPlayer = FVector::DistSquared(cameraPos, playerPos);

	float angle = FMath::Acos(FMath::Sqrt(camToMiddle / camToPlayer));
	angle = FMath::RadiansToDegrees(angle);

	UCharacterMovementComponent* moveComp = Cast<UCharacterMovementComponent>(GetCharacter()->GetMovementComponent());
	if(angle > (pCamComp->FieldOfView + m_OutOfScreenOffset) / 2.0f)		//Temporary magical nr
	{
		moveComp->MaxWalkSpeed = m_OutOfScreenSpeed;
		moveComp->SetFixedBrakingDistance(m_OutOfScreenBreakDist);
		moveComp->MaxAcceleration = m_OutOfScreenAcc;
	}
	else
	{
		moveComp->MaxWalkSpeed = m_PlayerSpeed;
		moveComp->SetFixedBrakingDistance(m_PlayerBreakDist);
		moveComp->MaxAcceleration = m_PlayerAcc;

	}
}

bool AMainPlayerController::GetHitPoint(FHitResult& result)
{
	UWorld* pWorld = GetWorld();

	if (pWorld)
	{
		FVector start = FVector::ZeroVector;
		FVector dir = FVector::ZeroVector;
		DeprojectMousePositionToWorld(start, dir);
		FVector end = start + (dir * 10000);

		return pWorld->LineTraceSingleByChannel(result, start, end, ECollisionChannel::ECC_Visibility);
	}

	return false;
}

void AMainPlayerController::SetEnableMove(bool enable)
{
	m_CanMove = enable;
}

void AMainPlayerController::SetEnableSwipe(bool enable)
{
	m_CanSwipe = enable;
}

void AMainPlayerController::SetSwipeDepth(float depth)
{
	m_SwipeX = depth;
}

void AMainPlayerController::Ignore()
{
	m_IsMouseDown = false;
}

bool AMainPlayerController::ProcessHit(FHitResult hit)
{
	APlayerCharacter* pCharacter = Cast<APlayerCharacter>(GetCharacter());
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, hit.Location);

	//check if point is reachable by navmesh
	FNavLocation NavLoc;
	FVector QueryingExtent = FVector(50.0f, 50.0f, 50.0f);
	FNavAgentProperties NavAgentProps;
	auto world=GetWorld();


	UNavigationSystemV1* NavigationArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	auto bProjectedLocationValid = NavigationArea->ProjectPointToNavigation(hit.Location, NavLoc, QueryingExtent);
	//->ProjectPointToNavigation(hit.Location, NavLoc, QueryingExtent);
		
	if (bProjectedLocationValid)
	SpawnNavParticle(hit.Location);

	if (hit.Actor != nullptr)
	{
		//STOP sitting
		pCharacter->SetSitting(false);
		//Player interaction
		if (hit.Actor == pCharacter)
		{
			SpawnSparkleParticle(hit.ImpactPoint);
			pCharacter->InteractWithSelf();
			return true;
		}

		IInteractable* pInteractable = Cast<IInteractable>(hit.Actor.Get());
		if (pInteractable)
		{
			SpawnSparkleParticle(hit.ImpactPoint);
			if (hit.Actor->IsA(ADateTreeActor::StaticClass()))
				pInteractable->Interact(pCharacter);				//EDGE CASE
			else
				pCharacter->SetInteractable(hit.Actor.Get());

			return true;
		}					
		else
			pCharacter->SetInteractable(nullptr);
	}

	return false;
}