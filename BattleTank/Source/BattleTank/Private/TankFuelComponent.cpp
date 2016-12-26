// Copyright MKProductions

#include "BattleTank.h"
#include "TankFuelComponent.h"


// Sets default values for this component's properties
UTankFuelComponent::UTankFuelComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UTankFuelComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentFuel = StartingFuel;	
}

int32 UTankFuelComponent::GetFuelAmount() const
{
	return CurrentFuel;
}

void UTankFuelComponent::SetFuelAmount(int32 FuelAmount)
{
	CurrentFuel = FuelAmount;
}

