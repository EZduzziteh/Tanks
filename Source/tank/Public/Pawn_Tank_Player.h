// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Pawn_Tank_Player.generated.h"

class UTankBarrel; // forward declare

UCLASS()
class TANK_API APawn_Tank_Player : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);


protected: 
	UTankAimingComponent* TankAimingComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	APawn_Tank_Player();

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
