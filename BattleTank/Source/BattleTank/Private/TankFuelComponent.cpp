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

void UTankFuelComponent::BeginPlay()
{
	Super::BeginPlay();
}

EFuelState UTankFuelComponent::GetFuelState() const
{
	return FuelState;
}

void UTankFuelComponent::SetFuelAmount(int32 FuelAmount)
{
	FuelCount = FuelAmount;
}

void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	TankMovingBurnFuel();

	TankFlameThrowerBurnFuel();

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
	return FuelCount;
}

void UTankFuelComponent::TankMovingBurnFuel()
{
	if (!ensure(Fuel)) { return; }
	auto CurrentPositionOfTank = Fuel->GetComponentLocation();
	if (!CurrentPositionOfTank.Equals(TankPosition, 1.f))
	{
		TankPosition = Fuel->GetComponentLocation();
		SetFuelAmount(GetFuelAmount() - 2);
	}
}

void UTankFuelComponent::TankFlameThrowerBurnFuel()
{
	if (IsFlameThrowerActive)
	{
		SetFuelAmount(GetFuelAmount() - 1);
	}
}

