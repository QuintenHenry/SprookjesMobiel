// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Characters/Player/PlayerCharacter.h"
#include "Materials/Material.h"
#include "WaterWell.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API AWaterWell : public AActor
{
	GENERATED_BODY()
	
public:	
	AWaterWell();

	void AddWoodLog();
	void AddRope();

	UFUNCTION(BlueprintPure)
	FORCEINLINE bool GetCompleted()
	{
		return m_IsCompleted;
	}

	UFUNCTION(BlueprintPure)
	FORCEINLINE FVector GetOffset()
	{
		return m_Offset;
	}

protected:
	virtual void BeginPlay() override;
	
private:
	//Components
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, DisplayName = "WellMesh", Category = "Components", Meta=(AllowPrivateAccess="true"))
	UStaticMeshComponent* m_pWellMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, DisplayName = "Log1Mesh", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_pLog1Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, DisplayName = "Log2Mesh", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_pLog2Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, DisplayName = "Log3Mesh", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_pLog3Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, DisplayName = "RopeMesh", Category = "Components", Meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* m_pRopeMesh;

	//Variables
	UPROPERTY(EditAnywhere, DisplayName = "Mushin spawn timer", Category = "Default")
	float m_MushinSpawnTimer;

	UPROPERTY(EditAnywhere, DisplayName = "Offset", Category = "Default")
	FVector m_Offset;

	UPROPERTY(EditAnywhere, DisplayName = "Well Material", Category = "Default")
	UMaterialInterface *m_WellMaterial;

	int m_CurrentLogs = 0;
	const int m_RequiredLogs = 3;
	bool m_CanSpawnMuhsin;
	APlayerCharacter* m_pMushin;
	bool m_IsCompleted;

	//Helper functions
	void SetCompleted();
	void SpawnMushin();	
};