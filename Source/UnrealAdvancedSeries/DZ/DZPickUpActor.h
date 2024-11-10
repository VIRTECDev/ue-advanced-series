// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DZPickUpActor.generated.h"


// Base game pick up class
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickupCollected);

UCLASS(Abstract)
class UNREALADVANCEDSERIES_API ADZPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADZPickUpActor();

	FOnPickupCollected OnPickupColllected;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Components declarations
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Components")
	class UStaticMeshComponent* PickupMeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Components")
	class USphereComponent* PickupSphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup Components")
	class UTextRenderComponent* PickupTextRenderComponent;

	// Variables declarations
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup params")
	float Value;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup params")
	FText DisplayText;

	UFUNCTION()
	void UpdateTextRotation(class UTextRenderComponent* TextRenderComponent);

	UFUNCTION(BlueprintCallable, Category = "Pickup params")
	void CodeHandleAbsorbing(float InputValue, FVector ActorPosition);


	UFUNCTION(BlueprintCallable, Category = "Delegate")
	void CallPickupCollected();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
