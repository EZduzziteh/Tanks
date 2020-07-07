// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Track.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANK_API UTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category = input)
	void SetThrottle(float Throttle);
	
	UPROPERTY(EditAnywhere, Category = Movement)
		float TrackMaxDrivingForce = 400000;
};
