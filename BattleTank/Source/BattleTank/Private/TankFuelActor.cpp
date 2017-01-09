// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuelActor.h"


void ATankFuelActor::BeginPlay()
{
	Super::BeginPlay();
	FuelCount = StartingFuel;
}

void ATankFuelActor::SetFuelAmount(int32 FuelAmount)
{
	FuelCount = FuelAmount;
	if (FuelCount < 0)
	{
		FuelCount = 0;
	}
}

int32 ATankFuelActor::GetFuelAmount() const
{
	return FuelCount;
}

bool ATankFuelActor::IsThereFuel()
{
	return (GetFuelAmount() > 0);
}

