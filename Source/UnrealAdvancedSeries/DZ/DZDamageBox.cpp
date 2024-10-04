// Fill out your copyright notice in the Description page of Project Settings.


#include "DZDamageBox.h"
#include "MyInterface.h"

ADZDamageBox::ADZDamageBox()
{
	PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &ADZDamageBox::OnDamageBoxBeginOverlap);
}

void ADZDamageBox::BeginPlay()
{
	Super::BeginPlay();

	BaseDamage = 10.0f;
}

void ADZDamageBox::OnDamageBoxBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->GetClass()->ImplementsInterface(UMyInterface::StaticClass()))
	{
		IMyInterface::Execute_RemoveHealth(OtherActor, BaseDamage);
	}
}

void ADZDamageBox::Tick(float DeltaTime)
{

}