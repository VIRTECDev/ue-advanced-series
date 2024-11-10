// Fill out your copyright notice in the Description page of Project Settings.


#include "DZLightSource.h"
#include "Kismet/GameplayStatics.h"
#include "DZPickUpActor.h"

// Sets default values
ADZLightSource::ADZLightSource()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADZLightSource::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADZLightSource::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

