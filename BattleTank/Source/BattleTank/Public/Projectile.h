// Copyright MKProductions

#pragma once

#include "Weapons.h"
#include "Projectile.generated.h"


UCLASS()
class BATTLETANK_API AProjectile : public AWeapons
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDamage = 20.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileDestroyDelay = 8.f;
};
