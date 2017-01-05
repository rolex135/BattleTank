// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "ItemFuel.generated.h"

/*
Spawnable actor to world.
Adds fuel to tank if tank drives over it
*/
UCLASS()
class BATTLETANK_API AItemFuel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemFuel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 FuelAmountToAdd;

	int32 MaxFuelToAdd = 400;
	
	int32 MinFuelToAdd = 50;
};
