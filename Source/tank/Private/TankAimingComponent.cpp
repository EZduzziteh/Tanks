// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "tank/Public/TankBarrel.h"
#include "tank/Public/TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {

	if (!BarrelToSet) {
		return;
	}
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) {

	if (!TurretToSet) {
		return;
	}
	Turret = TurretToSet;
}



void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {

	if (!Barrel) {
		return;
	}

	FVector OutLaunchVelocity;
	FVector StartLocation=Barrel->GetSocketLocation(FName("LaunchSocket"));

	

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(

		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace



	);
		
	if(bHaveAimSolution)
	{


		//calc out launch vel

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();

		//aim solution found
		MoveBarrelTowards(AimDirection);
	}
	else {
		//no aim solution found
		

	}
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {


	auto BarrelRotator= Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);//TODO remove magic number
	Turret->Rotate(DeltaRotator.Yaw);
}
