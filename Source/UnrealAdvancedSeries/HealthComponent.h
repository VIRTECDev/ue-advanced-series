// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALADVANCEDSERIES_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/** Add health to the current health, even if you try to add negative values */
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float HealthToAdd);

	/** Remove health from the current health, even if you try to add positive values */
	UFUNCTION(BlueprintCallable, Category = "Health")
	void RemoveHealth(float HealthToRemove);

	/** Set the health to a new value, this will override the current health */
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetHealth(float NewHealth);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float InitialHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float MaxHealth;
	
private:

	UPROPERTY(VisibleDefaultsOnly, Category = "Health")
	float Health;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
