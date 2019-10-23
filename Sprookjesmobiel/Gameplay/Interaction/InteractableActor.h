// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gameplay/Interaction/Interactable.h"
#include "InteractableActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USphereComponent;
class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AInteractableActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	//Functions
	virtual void BeginPlay() override;

	//Components	
	UPROPERTY(VisibleAnywhere, DisplayName = "Static Mesh Component", Category = "Components")
	UStaticMeshComponent* m_pStaticMeshComp;

	UPROPERTY(VisibleAnywhere, DisplayName = "Collision Component", Category = "Components")
	UBoxComponent* m_pCollisionComp;

	UPROPERTY(VisibleAnywhere, DisplayName = "Trigger Component", Category = "Components")
	USphereComponent* m_pTriggerComp;

	//Variables
	UPROPERTY(EditAnywhere, DisplayName = "Required Item", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pRequiredItem;

	UPROPERTY(EditAnywhere, DisplayName = "Reward", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pReward;
};