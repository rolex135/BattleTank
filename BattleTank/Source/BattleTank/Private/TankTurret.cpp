// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + ElevationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}

