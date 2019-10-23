// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/Interaction/InteractableActor.h"
#include "DateActor.generated.h"

class UBaseItem;

UCLASS()
class SPROOKJESMOBIEL_API ADateActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ADateActor();

	virtual void Interact(APlayerCharacter* pPlayer) override;
	UFUNCTION()
	void Disable();
	UFUNCTION()
	void Enable();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, DisplayName = "Date Item 1", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pDateItem;
	UPROPERTY(EditAnywhere, DisplayName = "Dates Item 2", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pDateItem2;
	UPROPERTY(EditAnywhere, DisplayName = "Dates Item 3", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pDateItem3;

	bool GotDates;
};
