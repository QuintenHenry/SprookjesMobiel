// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InfoObjectsWidget.generated.h"

UCLASS()
class SPROOKJESMOBIEL_API UInfoObjectsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UInfoObjectsWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintNativeEvent)
	void Show();
	virtual void Show_Implementation();

	void Update();
	UFUNCTION(BlueprintCallable)
	void SetMax(int32 newMax);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "ObjectsFound", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_ObjectsFoundString;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "MaxObjects", Category = "UI", Meta = (AllowPrivateAccess = "true"))
	FString m_MaxObjectsString;

	int32 m_ObjectsFound;
	int32 m_MaxObjects;
};