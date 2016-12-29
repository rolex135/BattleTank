// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuel.h"

void UTankFuel::BeginPlay()
{
	Super::BeginPlay();
	FuelCount = StartingFuel;
}

void UTankFuel::SetFuelAmount(int32 FuelAmount)
{
	FuelCount = FuelAmount;
	if (FuelCount < 0)
	{
		FuelCount = 0;
	}
}

int32 UTankFuel::GetFuelAmount() const
{
	return FuelCount;
}

bool UTankFuel::IsThereFuel()
{
	return (GetFuelAmount() > 0);
}