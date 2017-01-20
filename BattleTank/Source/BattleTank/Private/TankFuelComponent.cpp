// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuelComponent.h"
#include "TankFuel.h"

// Sets default values for this component's properties
UTankFuelComponent::UTankFuelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankFuelComponent::Initialize(UTankFuel* FuelToSet)
{
	Fuel = FuelToSet;
}

EFuelState UTankFuelComponent::GetFuelState() const
{
	return FuelState;
}

void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	TankMovingBurnFuel();

	TankFlameThrowerBurnFuel();
	if (!Fuel) { return; }
	if (Fuel->GetFuelAmount() <= 0)
	{
		FuelState = EFuelState::Empty;
	}
	else if (Fuel->GetFuelAmount() >= (Fuel->StartingFuel / 2))
	{
		FuelState = EFuelState::Full;
	}
	else
	{
		FuelState = EFuelState::HalfFull;
	}
}

void UTankFuelComponent::TankMovingBurnFuel()
{
	if (!Fuel) { return; }
	auto CurrentPositionOfTank = Fuel->GetComponentLocation();
	if (!CurrentPositionOfTank.Equals(TankPosition, 1.f))
	{
		TankPosition = Fuel->GetComponentLocation();
		Fuel->SetFuelAmount(-2);
	}
}

void UTankFuelComponent::TankFlameThrowerBurnFuel()
{
	if (!Fuel) { return; }
	if (IsFlameThrowerActive && Fuel->IsThereFuel())
	{
		Fuel->SetFuelAmount(-1);
	}
}

