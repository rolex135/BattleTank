// Copyright MKProductions

#pragma once

#include "Items.h"
#include "ItemFuel.generated.h"

/*
Spawnable actor to world.
Adds fuel to tank if tank drives over it
*/
UCLASS()
class BATTLETANK_API AItemFuel : public AItems
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemFuel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int32 MaxFuelToAdd = 20000;
	
	int32 MinFuelToAdd = 50;
};
