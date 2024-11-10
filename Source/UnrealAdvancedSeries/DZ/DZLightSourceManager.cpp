// Fill out your copyright notice in the Description page of Project Settings.


#include "DZLightSourceManager.h"
#include "Kismet/GameplayStatics.h"
#include "DZPickUpActor.h"
#include "DZLightSource.h"

// Sets default values
ADZLightSourceManager::ADZLightSourceManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADZLightSourceManager::BeginPlay()
{
	Super::BeginPlay();

	BindToAllPickups();
}

void ADZLightSourceManager::BindToAllPickups()
{
	TArray <AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADZPickUpActor::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		ADZPickUpActor* PickupActor = Cast<ADZPickUpActor>(Actor);

		if (PickupActor)
		{
			PickupActor->OnPickupColllected.AddDynamic(this, &ADZLightSourceManager::OnPickupColllected);
		}
	}
}

void ADZLightSourceManager::OnPickupColllected()
{
	TArray <AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADZLightSource::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		ADZLightSource* LightSource = Cast<ADZLightSource>(Actor);

		if (LightSource)
		{
			LightSource->ToggleLight();
		}
	}
}

// Called every frame
void ADZLightSourceManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

