// Fill out your copyright notice in the Description page of Project Settings.


#include "DZPickUpActor.h"
#include "Components/SphereComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ADZPickUpActor::ADZPickUpActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Creating components
	PickupMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMeshComp"));
	PickupSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphereComp"));
	PickupTextRenderComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("PickupTextRenderComponent"));

	// Attatching components
	RootComponent = PickupMeshComp;
	PickupSphereComp->SetupAttachment(RootComponent);
	PickupTextRenderComponent->SetupAttachment(RootComponent);
}	

// Called when the game starts or when spawned
void ADZPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADZPickUpActor::UpdateTextRotation(UTextRenderComponent* TextRenderComponent)
{
	if (!TextRenderComponent) return;
	if (!GetWorld()->GetFirstPlayerController()->GetPawn()) return;

	FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(
		TextRenderComponent->GetComponentLocation(),  // Start
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() //Target
	);

	TextRenderComponent->SetWorldRotation(NewRotation);
}

void ADZPickUpActor::CodeHandleAbsorbing(float InputValue, FVector ActorPosition)
{
	FVector CurrentLocation = PickupMeshComp->GetComponentLocation();
	FVector NewLocation = FMath::Lerp(CurrentLocation, ActorPosition, InputValue);

	PickupMeshComp->SetWorldLocation(NewLocation);
	FVector CurrentScale = PickupMeshComp->GetComponentScale();

	FVector NewScale = FMath::Lerp(CurrentScale, FVector(0.0f, 0.0f, 0.0f), InputValue);
	PickupMeshComp->SetWorldScale3D(NewScale);
}

// Called every frame
void ADZPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateTextRotation(PickupTextRenderComponent);
}

