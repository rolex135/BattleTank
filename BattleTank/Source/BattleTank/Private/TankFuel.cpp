// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuel.h"

void UTankFuel::BeginPlay()
{
	Super::BeginPlay();
	FuelCount = StartingFuel;
}

void UTankFuel::DecreaseOrAddFuel(int32 FuelAmount)
{
	FuelCount = FuelAmount + FuelCount;
	
}

int32 UTankFuel::GetFuelAmount() const
{
	return FuelCount;
}

bool UTankFuel::IsThereFuel() const
{
	return (GetFuelAmount() > 0);
}