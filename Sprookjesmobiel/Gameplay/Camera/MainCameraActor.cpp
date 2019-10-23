// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCameraActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Characters/Player/MainPlayerController.h"
#include "Engine/TargetPoint.h"

// Sets default values
AMainCameraActor::AMainCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	RootComponent = m_pCameraComponent;

	m_Force = 0;
}

// Called when the game starts or when spawned
void AMainCameraActor::BeginPlay()
{
	Super::BeginPlay();
	m_pCameraComponent->SetWorldRotation(FRotator(-m_Angle, 0, 0));

	TArray<AActor*> pArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), pArray);
	if(pArray.Num() > 0)
	{
		if(pArray.Num() == 1)
		{
			FVector spawnPos = pArray[0]->GetActorLocation();
			SetCameraLocation(spawnPos);
		}
		else
		{
			for(int i = 0; i < pArray.Num(); ++i)
			{
				if(pArray[i]->GetName() == FString{"CameraStart"})
				{
					FVector spawnPos = pArray[i]->GetActorLocation();
					SetCameraLocation(spawnPos);
				}
			}
		}
		
	}
	else
	{
		FVector spawnPos = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
		SetCameraLocation(spawnPos);
	}
}

// Called every frame
void AMainCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AMainPlayerController* pController = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(!pController /*|| !pController->GetEnableMove()*/) return;

	ACharacter* pPlayer = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if(!pPlayer) return;

	//Add force to camera
	m_pCameraComponent->AddWorldTransform(FTransform(FVector(0.0f, -m_Speed * m_Force * DeltaTime, 0.0f)));

	//Check if boundaries are reached
	FVector camPos = m_pCameraComponent->GetComponentLocation();
	if(camPos.Y < m_LeftBoundaryY )
		m_pCameraComponent->SetWorldLocation(FVector(camPos.X, m_LeftBoundaryY, camPos.Z));
	else if(camPos.Y > m_RightBoundaryY)
		m_pCameraComponent->SetWorldLocation(FVector(camPos.X, m_RightBoundaryY, camPos.Z));
	
	//Decelerate
	m_Force -= m_Force * m_DecelerationMultiplier * DeltaTime;

	//Set force to 0 if too low
	if(FMath::Abs(m_Force) < 10.0f)
		m_Force = 0.0f;
	else
		pController->MovePlayerToCamera(camPos.Y);

	//Set camera height relative to player height
	FVector actorPos = m_pCameraComponent->GetComponentLocation();
	FVector playerPos = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();
	
	
	if(playerPos.Z > m_DefaultHeight)
	{
		float newZ = FMath::Lerp<float>(m_pCameraComponent->GetComponentLocation().Z, UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation().Z, m_UpSpeed);
		FVector newPos = FVector(actorPos.X, actorPos.Y, newZ);
		m_pCameraComponent->SetWorldLocation(newPos);
	}
	else if(actorPos.Z > m_DefaultHeight)
	{
		float newZ = FMath::Lerp<float>(m_pCameraComponent->GetComponentLocation().Z, m_DefaultHeight, m_UpSpeed);
		FVector newPos = FVector(actorPos.X, actorPos.Y, newZ);
		m_pCameraComponent->SetWorldLocation(newPos);
	}
	else if(actorPos.Z < m_DefaultHeight)
	{
		FVector newPos = FVector(actorPos.X, actorPos.Y, m_DefaultHeight);
		m_pCameraComponent->SetWorldLocation(newPos);
	}

}

void AMainCameraActor::SetForce(float force)
{
	m_Force = force;
}

void AMainCameraActor::SetSpeed(float speed)
{
	m_Speed = speed;
}

void AMainCameraActor::SetCameraBoundaries(float leftBoundary, float rightBoundary)
{
	m_LeftBoundaryY = leftBoundary;
	m_RightBoundaryY = rightBoundary;
}

void AMainCameraActor::SetCameraLocation(FVector newLocation)
{
	//Camera itself
	m_pCameraComponent->SetWorldLocation(newLocation);

	//Set default height
	m_DefaultHeight = newLocation.Z;
}

