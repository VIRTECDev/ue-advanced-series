// Fill out your copyright notice in the Description page of Project Settings.


#include "SPickUpActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASPickUpActor::ASPickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);
}

// Called when the game starts or when spawned
void ASPickUpActor::BeginPlay()
{
	Super::BeginPlay();
}

void ASPickUpActor::DisplayTextToFollowPlayer(UTextRenderComponent* TextRenderComponent)
{
	// Find the look at rotation
	FRotator NewLookRotation = UKismetMathLibrary::FindLookAtRotation(TextRenderComponent->GetComponentLocation(),
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());

	// Set the rotation to the text render component
	TextRenderComponent->SetWorldRotation(NewLookRotation);
}

// Called every frame
void ASPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

