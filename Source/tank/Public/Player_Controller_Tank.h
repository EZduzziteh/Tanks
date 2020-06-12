// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn_Tank_Player.h"

#include "GameFramework/PlayerController.h"

#include "Player_Controller_Tank.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API APlayer_Controller_Tank : public APlayerController
{
	GENERATED_BODY()


public:
	APawn_Tank_Player* GetControlledTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float deltatime) override;
	//Startmoving the barrel so that a shot would hit crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrosshairXLoc = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLoc = 0.33333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
};
