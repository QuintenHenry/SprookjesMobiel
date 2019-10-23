// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gameplay/Interaction/Interactable.h"
#include "UI/InfoObjectsWidget.h"
#include "Gameplay/Interaction/InfoActor.h"
#include "PlayerCharacter.generated.h"

class UStaticMeshComponent;
class AMainCameraActor;
class UInventoryWidget;
class ANPCPawnBase;
class UBaseItem;
class UInfoObjectsComponent;
class AInfoActor;

UENUM(BlueprintType)
enum class ESickNPC : uint8
{
	ENone		UMETA(DisplayName = "None"),
	EFirst		UMETA(DisplayName = "First"),
	ESecond		UMETA(DisplayName = "Second"),
	EThird		UMETA(DisplayName = "Third")
};

UENUM(BlueprintType)
enum class EObjective : uint8
{
	ENone				UMETA(DisplayName = "None"),
	EGoToFirstPerson	UMETA(DisplayName = "Go to First Person"),
	ECureFirstPerson	UMETA(DisplayName = "Cure First Person"),
	EGoToSecondPerson	UMETA(DisplayName = "Go to Second Person"),
	ECureSecondPerson	UMETA(DisplayName = "Cure Second Person"),
	EGoToThirdPerson	UMETA(DisplayName = "Go to Third Person"),
	ECureThirdPerson	UMETA(DisplayName = "Cure Third Person"),
	ENext				UMETA(DisplayName = "To be determined")
};

USTRUCT(BlueprintType)
struct FGameInfo
{
	GENERATED_USTRUCT_BODY()

	bool IsSickPerson1Cured = false;
	bool IsSickPerson2Cured = false;
	bool IsSickPerson3Cured = false;
	bool IsMuhsinCured = false;

	EObjective Objective = EObjective::ENone;
};

UCLASS()
class SPROOKJESMOBIEL_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	void InteractWithSelf();
	void SetInfoActor(AInfoActor* pInfoObject);


	//Setters
	UFUNCTION(BluePrintCallable)
	void SetCamera(AMainCameraActor* pCamera);

	UFUNCTION(BluePrintCallable)
	void SetInventory(UInventoryWidget* pInventory);

	UFUNCTION(BlueprintCallable)
	void SetInteractable(AActor* pInteractable);

	UFUNCTION(BlueprintCallable)
	void SetActiveNPC(ANPCPawnBase* pNPC);

	//Getters
	UFUNCTION(BlueprintCallable)
	FORCEINLINE AMainCameraActor* GetCamera() const 
	{ 
		return m_pCamera; 
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UInventoryWidget* GetInventory() const
	{
		return m_pInventory;
	}

	FORCEINLINE AActor* GetInteractable() const
	{
		return m_pCurrentInteractable;
	}

	UFUNCTION(BlueprintPure)
	FORCEINLINE ANPCPawnBase* GetActiveNPC() const
	{
		return m_pActiveDialogueNPC;
	}
	
	UFUNCTION(BlueprintCallable)
	FORCEINLINE FGameInfo& GetGameInfo()
	{
		return m_GameInfo;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool GetMuhsinCured() const
	{
		return m_GameInfo.IsMuhsinCured;
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UStaticMeshComponent* GetBlindfoldMesh()
	{
		return m_pBlindfoldMesh;
	}

	UFUNCTION(BlueprintImplementableEvent)
	void SetSitting(bool value);

	FORCEINLINE UInfoObjectsComponent* GetInfoComponent()
	{
		return m_pInfoComponent;
	}

	FORCEINLINE AInfoActor* GetActiveInfoObject() {
		return m_pActiveInfoObject;
	}

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, DisplayName = "BlindfoldMesh", Category = "Components")
	UStaticMeshComponent* m_pBlindfoldMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, DisplayName = "Info Component", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UInfoObjectsComponent* m_pInfoComponent;

	UPROPERTY(EditAnywhere, DisplayName = "Camera Class", Category = "Gameplay")
	TSubclassOf<AActor> m_CameraToSpawn;

	UPROPERTY(VisibleAnywhere, DisplayName = "Camera", Category = "Gameplay")
	AMainCameraActor* m_pCamera;

	UPROPERTY(EditAnywhere, DisplayName = "Leaves Class", Category = "Gameplay")
	TSubclassOf<UBaseItem> m_pLeavesClass;

	UPROPERTY(VisibleAnywhere, DisplayName = "Inventory", Category = "Gameplay")
	UInventoryWidget* m_pInventory;

	FGameInfo m_GameInfo;
	AActor* m_pCurrentInteractable;
	ANPCPawnBase* m_pActiveDialogueNPC;

	UInfoObjectsWidget* m_pInfoWidget;
	AInfoActor* m_pActiveInfoObject;
};