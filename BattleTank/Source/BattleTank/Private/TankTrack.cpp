// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankSuspension.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::Initialize(UTankSuspension* LeftSuspensionToSet, UTankSuspension* MiddleSuspensionToSet, UTankSuspension* RightSuspensionToSet)
{
	LeftSuspension = LeftSuspensionToSet;
	MiddleSuspension = MiddleSuspensionToSet;
	RightSuspension = RightSuspensionToSet;
}


void UTankTrack::SetThrottle(float Throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	DriveAllTracks();
	ApplySidewaysForce();
	CurrentThrottle = 0;
}


void UTankTrack::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::DriveAllTracks()
{
	LeftSuspension->DriveTrack(CurrentThrottle, TrackMaxDrivingForce);
	//MiddleSuspension->DriveTrack(CurrentThrottle, TrackMaxDrivingForce);
	RightSuspension->DriveTrack(CurrentThrottle, TrackMaxDrivingForce);
}