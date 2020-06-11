// Fill out your copyright notice in the Description page of Project Settings.

#include "tank/Public/Player_Controller_Tank.h"
#include "tank/Public/Pawn_Tank_Player.h"

APawn_Tank_Player* APlayer_Controller_Tank::GetControlledTank() const {

	if (Cast<APawn_Tank_Player>(GetPawn())) {
		UE_LOG(LogTemp, Warning, TEXT("Got Pawn_Tank_Player"));
		return Cast<APawn_Tank_Player>(GetPawn());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("couldnt get  Pawn_Tank_Player"));
		return NULL;
	}

	

	
}

void APlayer_Controller_Tank::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	APlayer_Controller_Tank::GetControlledTank();
}