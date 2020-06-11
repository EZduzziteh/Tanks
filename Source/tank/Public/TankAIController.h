// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Pawn_Tank_Player.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	APawn_Tank_Player* GetControlledTank() const;

	virtual void BeginPlay() override;

};

