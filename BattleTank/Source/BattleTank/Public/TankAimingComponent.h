// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

//Forward declaration
class UTankBarrel;
class UTankTurret;
class UTankFuel;
class UWeaponComponent;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet, UTankFuel* FuelToSet, UWeaponComponent* WeaponToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void ThrowFlame();

	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	UTankFuel* Fuel = nullptr;

	UWeaponComponent* Weapon = nullptr;

	bool bHaveAimSolution;

	double LastFireTime = 0;

	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 2.0f;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

};
