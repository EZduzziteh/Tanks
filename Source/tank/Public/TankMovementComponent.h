// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"


class UTrack;
/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta = (BluePrintSpawnableComponent))
class TANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()


public: 
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTrack* LeftTrackToSet, UTrack* RightTrackToSet);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = Input)
		void IntendTurnRight(float Throw);

private:
	
	UTrack* LeftTrack = nullptr;
	UTrack* RightTrack = nullptr;
	
};
