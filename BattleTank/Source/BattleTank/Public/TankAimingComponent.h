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

// Enum for fuel state
UENUM()
enum class EFuelState : uint8
{
	Full,
	HalfFull,
	Empty
};

//Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
class AFlameThrower;
class UTankFuelComponent;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet, UTankFuelComponent* TankFuelToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetFuelLeft() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void ThrowFlame();

	void AimAt(FVector HitLocation);

	EFiringState GetFiringState() const;

	EFuelState GetFuelState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFuelState FuelState = EFuelState::Full;

private:
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	UTankFuelComponent* Fuel = nullptr;

	bool bHaveAimSolution;

	double LastFireTime = 0;

	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float FlameDistance = 2000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AFlameThrower> FlameThrowerBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 AmmoCount = 20;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	virtual void BeginPlay() override;

};
