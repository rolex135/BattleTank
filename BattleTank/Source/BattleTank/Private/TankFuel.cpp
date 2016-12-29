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
}

int32 UTankFuel::GetFuelAmount() const
{
	return FuelCount;
}