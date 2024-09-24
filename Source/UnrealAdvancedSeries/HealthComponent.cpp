// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	SetHealth(InitialHealth);
	
}

void UHealthComponent::AddHealth(float HealthToAdd)
{
	// Absolute value of the health to add to avoid removing health
	float AbsoluteHealth = UKismetMathLibrary::Abs(HealthToAdd);
	SetHealth(Health + AbsoluteHealth);
}

void UHealthComponent::RemoveHealth(float HealthToRemove)
{
	// Absolute value of the health to remove to avoid adding health
	float AbsoluteHealth = UKismetMathLibrary::Abs(HealthToRemove);
	SetHealth(Health - AbsoluteHealth);
}

void UHealthComponent::SetHealth(float NewHealth)
{
	Health = UKismetMathLibrary::Clamp(NewHealth, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("Health is now %f"), Health);
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

