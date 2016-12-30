// Copyright MKProductions

#include "BattleTank.h"
#include "TankSuspension.h"


void UTankSuspension::DriveTrack(float CurrentThrottle, float TrackMaxDrivingForce)
{
	FVector ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

