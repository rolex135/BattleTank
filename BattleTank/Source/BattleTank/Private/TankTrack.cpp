// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//Throttle = FMath::Clamp<float>(Throttle, -1, 1);
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle, %f"), *Name, Throttle);
	
	//TODO clamp actual throttle value so player cant over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


