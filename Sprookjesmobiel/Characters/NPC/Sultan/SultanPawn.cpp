// Fill out your copyright notice in the Description page of Project Settings.

#include "SultanPawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/ArrowComponent.h"
#include "Engine/World.h"


ASultanPawn::ASultanPawn() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	m_pWalkTarget = CreateDefaultSubobject<UArrowComponent>(TEXT("WalkTarget"));
	//m_pMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
}
void ASultanPawn::BeginPlay() {
	Super::BeginPlay();
	m_Goal = m_pWalkTarget->GetComponentLocation();
}

void ASultanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector distance = m_Goal-GetActorLocation();

	if (distance.Size2D() > 200) {
		distance.Normalize();
		//Direction + gravity
		//m_pMovementComponent->AddInputVector(distance + FVector{0.0f,0.0f,-200*DeltaTime}); 
		float speed = 200.0f;
		SetActorLocation(GetActorLocation() + distance * speed*DeltaTime);

		FHitResult hit;
		FVector start = GetActorLocation() + FVector(0.f, 0.f, 10000.0f);
		FVector end = GetActorLocation() + FVector{ 0.0f, 0.0f, -10000.0f };

		FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
		RV_TraceParams.bTraceComplex = true;
		RV_TraceParams.bTraceAsyncScene = true;
		RV_TraceParams.bReturnPhysicalMaterial = false;
		RV_TraceParams.AddIgnoredActor(this);
		GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, RV_TraceParams);

		SetActorLocation(hit.Location + FVector{ 0.0f,0.0f,120.0f });


		m_Walking = true;
		m_pParticleComp->SetVisibility(false);
	}
	else if (m_Walking) {
			m_Walking = false;
			SetActorEnableCollision(true);
			m_pParticleComp->SetVisibility(true);
	}
}
