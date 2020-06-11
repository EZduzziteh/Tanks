// Fill out your copyright notice in the Description page of Project Settings.

#include "tank/Public/Pawn_Tank_Player.h"

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
	UE_LOG(LogTemp, Warning, TEXT("AiController Begin Play"));
	ATankAIController::GetControlledTank();
}