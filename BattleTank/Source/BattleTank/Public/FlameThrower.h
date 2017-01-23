// Copyright MKProductions

#pragma once

#include "Weapons.h"
#include "FlameThrower.generated.h"

UCLASS()
class BATTLETANK_API AFlameThrower : public AWeapons
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlameThrower();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float FireDamage = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float FireDestroyDelay = 2.f;
};
