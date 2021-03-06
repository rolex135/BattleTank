// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

//Enum for current weapon
UENUM()
enum class ECurrentWeapon : uint8
{
	Projectile,
	IceBlast
};

//Forward declarations
class AProjectile;
class AIceBlast;
class AFlameThrower;

//Resposible for showing current weapon, spawning actors and setting ammo count
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetCurrentWeapon(ECurrentWeapon WeaponToSet);

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	void DecreaseOrAddAmmo(int32 AmmoCountToDecreaseOrAdd);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetAmmoCount() const;

	void SpawnCurrentWeaponAndLaunch(FVector FiringLocation, FRotator FiringRotation);

	void SpawnFlameThrowerAndLaunch(FVector FiringLocation, FRotator FiringRotation);
	
	float GetCurrentWeaponLaunchSpeed() const;

	float GetProjectileLaunchSpeed() const;

	float GetIceBlastLaunchSpeed() const;

	float GetFlameThrowerLaunchSpeed() const;

	ECurrentWeapon GetCurrentWeapon() const;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	ECurrentWeapon CurrentWeapon = ECurrentWeapon::Projectile;

private:
	// Sets default values for this component's properties
	UWeaponComponent();

	virtual void BeginPlay();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AIceBlast> IceBlastBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AFlameThrower> FlameThrowerBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
	int32 AmmoCount;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float ProjectileLaunchSpeed = 8000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float IceBlastLaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float FlameThrowerLaunchSpeed = 2500.f;

	int32 StartingAmmo = 10;
};
