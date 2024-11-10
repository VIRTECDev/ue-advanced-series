// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DZLightSourceManager.generated.h"

UCLASS()
class UNREALADVANCEDSERIES_API ADZLightSourceManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADZLightSourceManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BindToAllPickups();
	
	UFUNCTION()
	void OnPickupColllected();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
