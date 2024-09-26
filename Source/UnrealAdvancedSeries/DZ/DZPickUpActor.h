// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DZPickUpActor.generated.h"


// Base game pick up class

UCLASS(Abstract)
class UNREALADVANCEDSERIES_API ADZPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADZPickUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Components")
	class UStaticMeshComponent* PickupMeshComp;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Components")
	class USphereComponent* PickupSphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup params")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup params")
	FText DisplayText;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
