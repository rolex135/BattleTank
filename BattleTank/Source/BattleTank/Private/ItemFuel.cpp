// Copyright MKProductions

#include "BattleTank.h"
#include "ItemFuel.h"


// Sets default values
AItemFuel::AItemFuel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemFuel::BeginPlay()
{
	Super::BeginPlay();
	FuelAmountToAdd = rand() % (MaxFuelToAdd - MinFuelToAdd + 1) + MinFuelToAdd;
	
}

