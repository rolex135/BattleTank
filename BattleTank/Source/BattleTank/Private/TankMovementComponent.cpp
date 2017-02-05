// Copyright MKProductions

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankFuel.h"
#include "TankSuspension.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::BeginPlay()
{
	Super::BeginPlay();
}
/*
void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet, UTankFuel* FuelToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	Fuel = FuelToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto TurnThrowZ = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(TurnThrowZ);
	IntendMoveForward(ForwardThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!(LeftTrack && RightTrack)) { return; }
	if (Fuel->IsThereFuel())
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!(LeftTrack && RightTrack)) { return; }
	if (Fuel->IsThereFuel())
	{
		LeftTrack->SetThrottle(Throw);
		RightTrack->SetThrottle(-Throw);
	}
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!(LeftTrack && RightTrack)) { return; }
	if (Fuel->IsThereFuel())
	{
		LeftTrack->SetThrottle(-Throw);
		RightTrack->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (!(LeftTrack && RightTrack)) { return; }
	if (Fuel->IsThereFuel())
	{
		LeftTrack->SetThrottle(-Throw);
		RightTrack->SetThrottle(-Throw);
	}
*/
void UTankMovementComponent::Initialize(UTankFuel* FuelToSet, UTankSuspension* LeftBackToSet, UTankSuspension* LeftMiddleToSet, UTankSuspension* LeftFrontToSet, UTankSuspension* RightBackToSet, UTankSuspension* RightMiddleToSet, UTankSuspension* RightFrontToSet)
{
	LeftBack = LeftBackToSet;
	LeftMiddle = LeftMiddleToSet;
	LeftFront = LeftFrontToSet;
	RightBack = RightBackToSet;
	RightMiddle = RightMiddleToSet;
	RightFront = RightFrontToSet;
	Fuel = FuelToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	auto TurnThrowZ = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntendTurnRight(TurnThrowZ);
	IntendMoveForward(ForwardThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (Fuel->IsThereFuel())
	{
		LeftBack->SetThrottle(Throw);
		LeftMiddle->SetThrottle(Throw);
		LeftFront->SetThrottle(Throw);
		RightBack->SetThrottle(Throw);
		RightMiddle->SetThrottle(Throw);
		RightFront->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (Fuel->IsThereFuel())
	{
		LeftBack->SetThrottle(Throw);
		LeftMiddle->SetThrottle(Throw);
		LeftFront->SetThrottle(Throw);
		RightBack->SetThrottle(-Throw);
		RightMiddle->SetThrottle(-Throw);
		RightFront->SetThrottle(-Throw);

	}
}
void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (Fuel->IsThereFuel())
	{
		LeftBack->SetThrottle(-Throw);
		LeftMiddle->SetThrottle(-Throw);
		LeftFront->SetThrottle(-Throw);
		RightBack->SetThrottle(Throw);
		RightMiddle->SetThrottle(Throw);
		RightFront->SetThrottle(Throw);
	}
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (Fuel->IsThereFuel())
	{
		LeftBack->SetThrottle(-Throw);
		LeftMiddle->SetThrottle(-Throw);
		LeftFront->SetThrottle(-Throw);
		RightBack->SetThrottle(-Throw);
		RightMiddle->SetThrottle(-Throw);
		RightFront->SetThrottle(-Throw);
	}
}
