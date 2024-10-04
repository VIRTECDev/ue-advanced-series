// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DZDamageBox.generated.h"

/**
 * 
 */
UCLASS()
class UNREALADVANCEDSERIES_API ADZDamageBox : public ATriggerBox
{
	GENERATED_BODY()
	
public:
	ADZDamageBox();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
	float BaseDamage;

	UFUNCTION()
	void OnDamageBoxBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	virtual void Tick(float DeltaTime) override;
};
