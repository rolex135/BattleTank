// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "ItemSpawnComponent.generated.h"

//Enum for different item types
UENUM()
enum class EItems : uint8
{
	Fuel,
	Ammo,
	Health
};

//Forward declarations
class AItemFuel;
class AItemAmmo;
class AItemHealth;

/*
Responsible for spawning random items in the world
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UItemSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemSpawnComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SpawnRandomItemActor(FVector LocationToSpawn);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AItemFuel> FuelBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AItemAmmo> AmmoBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AItemHealth> HealthBlueprint;

	//Hardcoded number of enum items, change this when adding to items to EItem enum class
	const uint8 NumberOfItems = 3;
};
