// Fill out your copyright notice in the Description page of Project Settings.

#include "tank/Public/Pawn_Tank_Player.h"
#include "Engine/World.h"
#include "tank/Public/TankAIController.h"


APawn_Tank_Player* ATankAIController::GetControlledTank() const {

	if (Cast<APawn_Tank_Player>(GetPawn())) {
		UE_LOG(LogTemp, Warning, TEXT("Got Pawn_Tank_Ai"));
		return Cast<APawn_Tank_Player>(GetPawn());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("couldnt get  Pawn_Tank_Ai"));
		return NULL;
	}




}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("found player tank"));


	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("couldnt find player tank"));

	}
}

void ATankAIController::Tick(float deltatime) {

	Super::Tick(deltatime);
	if (GetPlayerTank()) {
		Cast<APawn_Tank_Player>(GetPawn())->AimAt(GetPlayerTank()->GetActorLocation());
	}


}


APawn_Tank_Player* ATankAIController::GetPlayerTank() const {
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) {
		return nullptr;
	}
	return Cast<APawn_Tank_Player>(PlayerPawn);
}