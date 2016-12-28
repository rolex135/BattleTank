// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuel.h"


void UTankFuel::BeginPlay()
{
	Super::BeginPlay();
	CurrentFuel = StartingFuel;
}