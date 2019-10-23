// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Gameplay/Interaction/Interactable.h"
#include "NPCPawnBase.generated.h"

class UBoxComponent;
class UCapsuleComponent;
class USkeletalMeshComponent;
class UParticleSystemComponent;

UCLASS()
class SPROOKJESMOBIEL_API ANPCPawnBase : public APawn, public IInteractable
{
	GENERATED_BODY()

public:
	ANPCPawnBase();

	virtual void Interact(APlayerCharacter* pPlayer) override;
	void ShowQuestMarker(bool visible);

	FORCEINLINE bool IsPlayerClose() const
	{
		return m_IsPlayerClose;
	}

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

	//Components
	UPROPERTY(VisibleAnywhere, DisplayName = "Trigger Component", Category = "Components")
	UBoxComponent* m_pTriggerComp;

	UPROPERTY(VisibleAnywhere, DisplayName = "Capsule Collider", Category = "Components")
	UCapsuleComponent* m_pCapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, DisplayName = "Skeletal Mesh", Category = "Components")
	USkeletalMeshComponent* m_pSkeletalMeshComp;

	UPROPERTY(VisibleAnywhere, DisplayName = "Particle System", Category = "Components")
	UParticleSystemComponent* m_pParticleComp;

	//Variable
	bool m_IsPlayerClose;
};
