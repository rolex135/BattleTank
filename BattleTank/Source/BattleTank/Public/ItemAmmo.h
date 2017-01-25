// Copyright MKProductions

#pragma once

#include "Items.h"
#include "ItemAmmo.generated.h"

UCLASS()
class BATTLETANK_API AItemAmmo : public AItems
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemAmmo();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int32 MaxAmmoToAdd = 10;

	int32 MinAmmoToAdd = 1;
};
