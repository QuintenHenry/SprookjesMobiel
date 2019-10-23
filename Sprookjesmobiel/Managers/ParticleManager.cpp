// Fill out your copyright notice in the Description page of Project Settings.

#include "ParticleManager.h"
#include "Kismet/GameplayStatics.h"

AParticleManager::AParticleManager()
{
	PrimaryActorTick.bCanEverTick = false;

	//m_Particles.SetNumUninitialized(0);
}

void AParticleManager::BeginPlay()
{
	Super::BeginPlay();
}

void AParticleManager::SpawnParticle(const FString& name, const FVector& worldPos)
{
	FParticle* pParticle = m_Particles.FindByPredicate([name](const FParticle& element) {
		return element.Name.Equals(name);
	});

	if (pParticle)
	{
		FTransform spawnTransform;
		spawnTransform.SetLocation(worldPos);

		
		UParticleSystemComponent* pTempParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), pParticle->pParticleSystem, spawnTransform);

		if(name == "Shake")
		{
			if(m_pShakeParticle) 
			{
				m_pShakeParticle->DestroyComponent();
				m_pShakeParticle = nullptr;
			}
			m_pShakeParticle = pTempParticle;
		}
		else if(name == "Swipe")
			m_pSwipeParticle = pTempParticle;

		//m_SpawnedParticles.Push(UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), pParticle->pParticleSystem, spawnTransform));
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("ParticleManager::SpawnParticle - Particle not found"));
}
/*void AParticleManager::SpawnParticle(const FString& name, const FVector& worldPos, const FVector scale)
{
	FParticle* pParticle = m_Particles.FindByPredicate([name](const FParticle& element) { 
		return element.Name.Equals(name);
	});

	if (pParticle)
	{
		FTransform spawnTransform;
		spawnTransform.SetLocation(worldPos);
		spawnTransform.SetScale3D(scale);

		if(name == "Shake")
			m_pShakeParticle = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), pParticle->pParticleSystem, spawnTransform);
		//m_SpawnedParticles.Push(UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), pParticle->pParticleSystem, spawnTransform));
	} else
		UE_LOG(LogTemp, Warning, TEXT("ParticleManager::SpawnParticle - Particle not found"));
}*/

void AParticleManager::StopShakeParticle() 
{

	if(!m_pShakeParticle)
		return;

	m_pShakeParticle->DestroyComponent();
	m_pShakeParticle = nullptr;
	/*
	FParticle* pParticle = m_Particles.FindByPredicate([name](const FParticle& element) {
		return element.Name.Equals(name);
	});
	if (pParticle) {
		auto particle = m_SpawnedParticles.FindByPredicate([pParticle](const UParticleSystemComponent* element) {
			return (element->Template == pParticle->pParticleSystem);
		});
		for (int i = 0; i < m_SpawnedParticles.Num(); ++i)//UParticleSystemComponent* particle : m_SpawnedParticles)
		{
			if (m_SpawnedParticles[i]->Template == pParticle->pParticleSystem)
			{
				UParticleSystemComponent* pParticleToDelete = m_SpawnedParticles[i];
				m_SpawnedParticles.RemoveAt(i);
				pParticleToDelete->DestroyComponent();
			}
		}
	}*/
}

void AParticleManager::StopSwipeParticle()
{
	if(!m_pSwipeParticle)
		return;

	m_pSwipeParticle->DestroyComponent();
	m_pSwipeParticle = nullptr;
}