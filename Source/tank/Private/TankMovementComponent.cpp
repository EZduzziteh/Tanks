// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "Track.h"


void UTankMovementComponent::IntendMoveForward(float Throw) {

	if (!LeftTrack || !RightTrack) {return;}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw) {

	if (!LeftTrack || !RightTrack) {return;}

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}



void UTankMovementComponent::Initialize(UTrack* LeftTrackToSet, UTrack* RightTrackToSet) {

	if (!LeftTrackToSet || !RightTrackToSet) {
		return;
	}

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;



}