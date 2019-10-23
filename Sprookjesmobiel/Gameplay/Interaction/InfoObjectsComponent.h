// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gameplay/Interaction/InfoActor.h"
#include "InfoObjectsComponent.generated.h"

class UInfoObjectsWidget;

USTRUCT(BlueprintType)
struct FMapClassKey
{
public:
	GENERATED_USTRUCT_BODY()

	FMapClassKey(const TSubclassOf<AInfoActor>& inClass = {})
	{
		Class = inClass;
	}

	UPROPERTY(EditAnywhere, DisplayName = "Class", Category = "Struct")
	TSubclassOf<AInfoActor> Class;

	friend bool operator==(const FMapClassKey& keyA, const FMapClassKey& keyB)
	{
		UClass* pClassA = keyA.Class.Get();
		UClass* pClassB = keyB.Class.Get();

		 if (pClassA == nullptr)
			 return pClassB != nullptr;
		 else if (pClassB == nullptr)
			 return false;

		 return pClassB->IsChildOf(pClassA);
	}

	friend uint32 GetTypeHash(const FMapClassKey& key)
	{
		return GetTypeHash(key.Class);
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPROOKJESMOBIEL_API UInfoObjectsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInfoObjectsComponent();

	bool Find(AInfoActor* pInfoObject);
	void UpdateUI();

	FORCEINLINE void SetActiveInfoObject(AInfoActor* pNew)
	{
		m_pActiveInfoObject = pNew;
	}
	FORCEINLINE AInfoActor* GetActiveInfoActor()
	{
		return m_pActiveInfoObject;
	}

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Found Objects", Category = "Gameplay", Meta = (AllowPrivateAccess = "true"))
	TMap<FMapClassKey, bool> m_FoundObjects;

	UInfoObjectsWidget* m_pInfoWidget;
	AInfoActor* m_pActiveInfoObject;
};