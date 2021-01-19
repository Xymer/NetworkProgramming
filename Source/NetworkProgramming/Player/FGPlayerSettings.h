// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FGPlayerSettings.generated.h"

/**
 *
 */
UCLASS()
class NETWORKPROGRAMMING_API UFGPlayerSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Movement)
		float Acceleration = 500.0f;

	UPROPERTY(EditAnywhere, Category = Movement, meta = (DisplayName = "TurnSpeed"))
		float TurnSpeedDefault = 100.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
		float MaxVelocity = 2000.0f;

	UPROPERTY(EditAnywhere, Category = Movement)
		float Friction = 0.75f;

	UPROPERTY(EditAnywhere, Category = Movement)
		float BrakingFriction = 0.001f;

};