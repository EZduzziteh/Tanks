// Fill out your copyright notice in the Description page of Project Settings.


#include "Track.h"


void UTrack::SetThrottle(float Throttle) {
	

	
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;

	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

	
}

