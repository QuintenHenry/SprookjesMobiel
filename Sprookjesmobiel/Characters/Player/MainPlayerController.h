// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInputDispatcher);

UCLASS()
class SPROOKJESMOBIEL_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMainPlayerController();

	//Setup the input for the player
	void SetupInputComponent() override;

	//Inherit update
	void Tick(float deltaTime) override;

	//Inherit init
	void BeginPlay() override;

	virtual void Possess(APawn* InPawn) override;
	FORCEINLINE FInputDispatcher& GetInputDispatcher()
	{
		return m_InputDispatcher;
	}

	void MovePlayerToCamera(float cameraY);

	//The distance between the camera and the player in which the player does not go towards the camera
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_FreemoveDistance;

	//The speed at which the player visibly moves
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_PlayerSpeed;

	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_OutOfScreenSpeed;

	//The acceleration and deceleration of the player
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_PlayerAcc;

	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_OutOfScreenAcc;

	//The distance the player starts slowing down
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_PlayerBreakDist;

	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_OutOfScreenBreakDist;

	//The depth the player walks one when swiping
	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_SwipeX;

	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_OutOfScreenOffset;

	UFUNCTION(BlueprintCallable)
	void SetEnableMove(bool enable);

	UFUNCTION(BlueprintCallable)
	void SetEnableSwipe(bool enable);

	UFUNCTION(BlueprintCallable)
	void SetSwipeDepth(float depth);

	FORCEINLINE bool GetEnableMove()
	{
		return m_CanMove;
	}

	UFUNCTION(BlueprintCallable)
	bool ProcessHit(FHitResult hit);

protected:
	//Set mouse button down
	void SetMouseDown();

	//Set mouse button up
	void SetMouseUp();

	void Ignore();

private:
	//Variables
	bool m_IsMouseDown;
	bool m_IsDragging;
	bool m_IsOutsideFOV;
	float m_CurrentCameraSpeed;
	float m_MouseHoldTimer;

	UPROPERTY(EditAnywhere, Category = "PlayerSettings")
	float m_MouseHoldTime;

	//The previous position of the mouse on click
	FVector2D m_PreviousMousePos;

	UPROPERTY()
	FInputDispatcher m_InputDispatcher;

	//Helper functions
	void ProcessMouseClicks(float deltaTime);
	void OnDrag(float deltaTime, FVector2D currentMousePos);
	void OnClick();
	void InteractWithWorld();
	void DialogueContinue();
	void SpawnNavParticle(const FVector& worldPos);
	void SpawnSparkleParticle(const FVector& worldPos);
	void SpeedupOutOfScreen();
	bool GetHitPoint(FHitResult& result);

	bool m_CanMove;
	bool m_CanSwipe;
};