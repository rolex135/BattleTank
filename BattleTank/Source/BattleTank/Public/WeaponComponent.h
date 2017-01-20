// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

//Enum for current weapon
UENUM()
enum class ECurrentWeapon : uint8
{
	MainWeapon,
	SecondaryWeapon
};

//Forward declarations
class AProjectile;
class AIceBlast;

//Resposible for showing current weapon and setting ammo count
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetCurrentWeapon(ECurrentWeapon WeaponToSet);

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	void DecreaseOrAddAmmo(int32 AmmoCountToDecrease);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetAmmoCount() const;

	void SpawnCurrentWeaponAndLaunch(FVector FiringLocation, FRotator FiringRotation, float LaunchSpeed);
	

	ECurrentWeapon GetCurrentWeapon() const;


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	ECurrentWeapon CurrentWeapon = ECurrentWeapon::MainWeapon;

private:
	// Sets default values for this component's properties
	UWeaponComponent();

	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	virtual void BeginPlay();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AIceBlast> IceBlastBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Ammo")
	int32 AmmoCount;

	int32 StartingAmmo = 10;
};
