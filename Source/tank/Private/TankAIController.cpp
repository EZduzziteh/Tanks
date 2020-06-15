// Fill out your copyright notice in the Description page of Project Settings.

#include "tank/Public/Pawn_Tank_Player.h"
#include "Engine/World.h"

#include "tank/Public/TankAIController.h"




void ATankAIController::BeginPlay() {

	Super::BeginPlay();
	


}

void ATankAIController::Tick(float deltatime) {


	Super::Tick(deltatime);
	auto ControlledTank = Cast<APawn_Tank_Player>(GetPawn());
	auto PlayerTank= Cast<APawn_Tank_Player>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	
		ControlledTank->Fire();
	}


}


