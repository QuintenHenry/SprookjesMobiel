// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainCameraActor.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AMainCameraActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainCameraActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetForce(float force);
	void SetSpeed(float speed);

	UFUNCTION(BlueprintCallable)
	void SetCameraBoundaries(float leftBoundary, float rightBoundary);

	UFUNCTION(BlueprintCallable)
	void SetCameraLocation(FVector newLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//How fast the camera can be dragged / swiped
	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_Speed;

	//How fast the camera centers itself
	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_LagSpeed;

	//The distance to the player at start
	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_Distance;

	//The angle of the camera
	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_Angle;

	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_RelativeHeight;

	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_LeftBoundaryY;

	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_RightBoundaryY;

	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_DecelerationMultiplier;

	UPROPERTY(EditAnywhere, Category = "CameraSettings")
	float m_UpSpeed;

	float m_Force;
	float m_DefaultHeight;

	//Components
	class UCameraComponent* m_pCameraComponent;
	class USpringArmComponent* m_pSpringArmComponent;
};
