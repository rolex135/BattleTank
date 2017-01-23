// Copyright MKProductions

#pragma once

#include "Weapons.h"
#include "IceBlast.generated.h"

UCLASS()
class BATTLETANK_API AIceBlast : public AWeapons
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AIceBlast();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float IceBlastDamage = 50.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float IceBlastDestroyDelay = 2.f;
};