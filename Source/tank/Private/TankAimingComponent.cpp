// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "tank/Public/TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {


	Barrel = BarrelToSet;
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

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: aim solution found"), Time);
		MoveBarrelTowards(AimDirection);
	}
	else {
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim Solve found"), Time);

	}
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {


	auto BarrelRotator= Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *DeltaRotator.ToString());

	Barrel->Elevate(5);//TODO remove magic number
}
