// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "Pawn_Tank_Player.generated.h"

// forward declarations
class UTankBarrel; 
class AProjectile;
class UTankTurret;

class UTankAimingComponent;
class UTankMovementComponent;

UCLASS()
class TANK_API APawn_Tank_Player : public APawn
{
	GENERATED_BODY()

public:
	
	//references
	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* BarrelToSet);


	UFUNCTION(BlueprintCallable, Category = Input	)
	void Fire();

	void AimAt(FVector HitLocation);

protected: 
	UTankAimingComponent* TankAimingComponent = nullptr;
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
private:
	// Sets default values for this pawn's properties
	APawn_Tank_Player();

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;

	UPROPERTY(EditAnywhere, Category = Firing)
		float ReloadTime= 1;


		double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	//local barel ref for spawning projectile
	UTankBarrel* Barrel = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
