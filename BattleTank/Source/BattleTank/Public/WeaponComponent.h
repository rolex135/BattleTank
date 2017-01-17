// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	UClass* CurrentWeapon();

	void SetAmmoCount(int32 AmmoCountToSet);

	int32 GetAmmoCount();

private:
	// Sets default values for this component's properties
	UWeaponComponent();

	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	virtual void BeginPlay();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	int32 AmmoCount;

	int32 StartingAmmo = 10;
};
