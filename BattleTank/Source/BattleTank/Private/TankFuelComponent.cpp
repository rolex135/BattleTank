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

void UTankFuelComponent::SetFuelAmount(int32 FuelAmount)
{
	if (!ensure(Fuel)) { return; }
	Fuel->CurrentFuel = FuelAmount;
}

void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (!ensure(Fuel)) { return; }
	if (GetFuelAmount() <= 0)
	{
		FuelState = EFuelState::Empty;
	}
	else if (GetFuelAmount() >= 200)
	{
		FuelState = EFuelState::Full;
	}
	else
	{
		FuelState = EFuelState::HalfFull;
	}
}

int32 UTankFuelComponent::GetFuelAmount() const
{
	return Fuel->CurrentFuel;
}

