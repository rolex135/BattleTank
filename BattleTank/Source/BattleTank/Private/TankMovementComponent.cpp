// Copyright MKProductions

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankFuelComponent.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	TankPosition = GetActorLocation();
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet, UTankFuelComponent* FuelToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	FuelComponent = FuelToSet;
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
	if (!ensure(LeftTrack && RightTrack && FuelComponent)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	if (!ensure(LeftTrack && RightTrack)) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::TankMoving()
{
	auto CurrentPositionOfTank = GetActorLocation();
	if (!CurrentPositionOfTank.Equals(TankPosition, 1.f))
	{
		int32 FuelToSet = FuelComponent->GetFuelAmount() - 1;
		FuelComponent->SetFuelAmount(FuelToSet);
		TankPosition = GetActorLocation();
	}
}
