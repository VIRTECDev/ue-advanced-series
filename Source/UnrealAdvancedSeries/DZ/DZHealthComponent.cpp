// Fill out your copyright notice in the Description page of Project Settings.


#include "DZHealthComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UDZHealthComponent::UDZHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDZHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	SetHealth(InitialHealth);

	// ...
	
}

void UDZHealthComponent::AddHealth(float HealthToAdd)
{
	float ClampedHealth = UKismetMathLibrary::Abs(HealthToAdd);
	SetHealth(Health + ClampedHealth);
}

void UDZHealthComponent::RemoveHealth(float HealthToRemove)
{
	float AbsoluteHealth = UKismetMathLibrary::Abs(HealthToRemove);
	SetHealth(Health - AbsoluteHealth);
}

void UDZHealthComponent::SetHealth(float NewHealth)
{
	Health = UKismetMathLibrary::Clamp(NewHealth, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("Current Health: %f"), Health);
}


// Called every frame
void UDZHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

