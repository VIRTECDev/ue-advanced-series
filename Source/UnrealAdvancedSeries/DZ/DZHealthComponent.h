// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DZHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALADVANCEDSERIES_API UDZHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDZHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float HealthToAdd);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void RemoveHealth(float HealthToRemove);

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetHealth(float SetHealth);

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float InitialHealth;

	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float Health;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
