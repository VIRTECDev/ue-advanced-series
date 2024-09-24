// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPickUpActor.generated.h"


// Forward Declarations
class USphereComponent;
class UStaticMeshComponent;
class UTextRenderComponent;

/**
 *  Base class for all pick up actors
 */

UCLASS(Abstract)
class UNREALADVANCEDSERIES_API ASPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPickUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PickupActor")
	float GrantedHealth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PickupActor")
	FText PickUpDisplayText;

	/** Fix the text to direction of the player, must update frequently */
	UFUNCTION(BlueprintCallable, Category = "PickupActor")
	void DisplayTextToFollowPlayer(UTextRenderComponent* TextRenderComponent);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
