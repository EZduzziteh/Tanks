// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawn_Tank_Player.h"

#include "GameFramework/PlayerController.h"

#include "Player_Controller_Tank.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API APlayer_Controller_Tank : public APlayerController
{
	GENERATED_BODY()


public:
	APawn_Tank_Player* GetControlledTank() const;

	virtual void BeginPlay() override;
	
};
