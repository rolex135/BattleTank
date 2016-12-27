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

void UTankFuelComponent::Initialize(UTankFuel* FuelToSet)
{
	Fuel = FuelToSet;
}

void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
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
	return CurrentFuel;
}

EFuelState UTankFuelComponent::GetFuelState() const
{
	return FuelState;
}

void UTankFuelComponent::SetFuelAmount(int32 FuelAmount)
{
	CurrentFuel = FuelAmount;
}

