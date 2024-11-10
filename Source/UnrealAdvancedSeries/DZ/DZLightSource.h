// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DZLightSource.generated.h"

UCLASS()
class UNREALADVANCEDSERIES_API ADZLightSource : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADZLightSource();

	UFUNCTION(BlueprintImplementableEvent, Category = "Light Source")
	void ToggleLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
