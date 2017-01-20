// Copyright MKProductions

#include "BattleTank.h"
#include "ItemSpawnComponent.h"
#include "ItemFuel.h"
#include "ItemAmmo.h"


UItemSpawnComponent::UItemSpawnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UItemSpawnComponent::SpawnRandomItemActor(FVector LocationToSpawn)
{
	if (!FuelBlueprint || !AmmoBlueprint) { return; }
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	//int32 NumberOfActors = 2;
	EItems RandomActorNumber = static_cast<EItems>(rand() % NumberOfItems);
	if (RandomActorNumber == EItems::Fuel)
	{
		GetWorld()->SpawnActor<AItemFuel>(FuelBlueprint, LocationToSpawn, FRotator(0.f, 0.f, 0.f), SpawnInfo);
	}
	else if (RandomActorNumber == EItems::Ammo)
	{
		GetWorld()->SpawnActor<AItemAmmo>(AmmoBlueprint, LocationToSpawn, FRotator(0.f, 0.f, 0.f), SpawnInfo);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not found"));
	}
}