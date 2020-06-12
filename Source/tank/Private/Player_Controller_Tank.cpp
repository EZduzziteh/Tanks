// Fill out your copyright notice in the Description page of Project Settings.

#include "tank/Public/Player_Controller_Tank.h"
#include "tank/Public/Pawn_Tank_Player.h"



void APlayer_Controller_Tank::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	APlayer_Controller_Tank::GetControlledTank();
}


void APlayer_Controller_Tank::Tick(float deltatime) {

	Super::Tick(deltatime);
	AimTowardsCrosshair();
	
	
}
APawn_Tank_Player* APlayer_Controller_Tank::GetControlledTank() const {

	if (Cast<APawn_Tank_Player>(GetPawn())) {
		
		return Cast<APawn_Tank_Player>(GetPawn());
	}
	else {
		
		return NULL;
	}




}
void APlayer_Controller_Tank::AimTowardsCrosshair() {
	if (!GetControlledTank()) {
		return;
	}

	FVector HitLocation;//out parameter
	
	if (GetSightRayHitLocation(HitLocation))//has side effect going to raytrace
	{
		GetControlledTank()->AimAt(HitLocation);
		
	} // get world loation with linetrace through crosshair

	//if hits something,//tell controlled tank to aim at this point.
}

bool APlayer_Controller_Tank::GetSightRayHitLocation(FVector& OutHitLocation) const{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLoc, ViewportSizeY * CrosshairYLoc);
	
	FVector LookDirection;		
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	return true;
}

bool APlayer_Controller_Tank::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {


	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
			)) 
	{
		HitLocation=HitResult.Location;
		return true;
	}
	else {
		HitLocation = FVector(0);
		return false;
	}

}



bool APlayer_Controller_Tank::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const{
	FVector CameraWorldLocation;
	
	return DeprojectScreenPositionToWorld(ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation, 
		LookDirection); 
	

	
}