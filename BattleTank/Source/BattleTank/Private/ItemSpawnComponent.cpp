// Copyright MKProductions

#include "BattleTank.h"
#include "ItemSpawnComponent.h"
#include "ItemFuel.h"


UItemSpawnComponent::UItemSpawnComponent()
{

	PrimaryComponentTick.bCanEverTick = false;
}

void UItemSpawnComponent::SpawnItem(FVector LocationToSpawn)
{
	FRotator RotationToSpawn(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AItemFuel>(LocationToSpawn, RotationToSpawn, SpawnInfo);
}