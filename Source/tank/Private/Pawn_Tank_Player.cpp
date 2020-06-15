// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawn_Tank_Player.h"
#include "TankAimingComponent.h"

// Sets default values
APawn_Tank_Player::APawn_Tank_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

void APawn_Tank_Player::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}
void APawn_Tank_Player::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void APawn_Tank_Player::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	
	UE_LOG(LogTemp, Warning, TEXT("%f: Fire"), Time);
}

// Called when the game starts or when spawned
void APawn_Tank_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


// Called to bind functionality to input
void APawn_Tank_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APawn_Tank_Player::AimAt(FVector HitLocation) {

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	}

