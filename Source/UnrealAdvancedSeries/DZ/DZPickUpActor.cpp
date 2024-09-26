// Fill out your copyright notice in the Description page of Project Settings.


#include "DZPickUpActor.h"
#include "Components/SphereComponent.h"

// Sets default values
ADZPickUpActor::ADZPickUpActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Creating components
	PickupMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMeshComp"));
	PickupSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphereComp"));
	
	// Attatching components
	RootComponent = PickupMeshComp;
	PickupSphereComp->SetupAttachment(RootComponent);
}	

// Called when the game starts or when spawned
void ADZPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADZPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

