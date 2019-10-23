// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
//#include "Containers/Array.h"
#include "DateTreeActor.generated.h"

class UArrowComponent;
class USkeletalMeshComponent;
class UAnimSequence;
class ADateActor;

UCLASS()
class SPROOKJESMOBIEL_API ADateTreeActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ADateTreeActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, DisplayName = "Spawn Position", Category = "Components")
	UArrowComponent* m_pSpawnPos;

	UPROPERTY(VisibleAnywhere, DisplayName = "Skeletal Mesh", Category = "Components")
	USkeletalMeshComponent* m_pSkeletalMeshComp;

	UPROPERTY(EditAnywhere, DisplayName = "Date Class", Category = "Gameplay")
	TSubclassOf<AActor> m_pDateClass;

	UPROPERTY(EditAnywhere, DisplayName = "Idle Animation", Category = "Animation")
	UAnimSequence* m_pIdleAnimation;

	UPROPERTY(EditAnywhere, DisplayName = "Shake Animation", Category = "Animation")
	UAnimSequence* m_pShakeAnimation;

	bool m_CanTakeDates{};
	bool m_TookDates{};
	FTimerHandle m_AnimHandle;
	void IdleAnimationHandler();

	int m_OldestIdx;
	const int m_MaxNrDates = 5;
	TArray<ADateActor*> m_pDateArray;	
};