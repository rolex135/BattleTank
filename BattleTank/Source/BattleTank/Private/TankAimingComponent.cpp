// Copyright MKProductions

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "FlameThrower.h"
#include "TankAimingComponent.h"
#include "TankFuel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::BeginPlay()
{
	//So that first fire is after reload
	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	if (!Fuel) { return; }

	Fuel->IsThereFuel();

	if (GetRoundsLeft() <= 0)
	{
		FiringState = EFiringState::OutOfAmmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
	}
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}


int32 UTankAimingComponent::GetRoundsLeft() const
{
	return AmmoCount;
}

void UTankAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet, UTankFuel* FuelToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
	Fuel = FuelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	//Calculate the out launch velocity
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }
	//Work out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);

	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Turret->RotateTurret(DeltaRotator.Yaw);
	}
	else//Avoid going long-way around
	{
		Turret->RotateTurret(-DeltaRotator.Yaw);
	}
}

void UTankAimingComponent::Fire()
{
	if(FiringState == EFiringState::Locked || FiringState == EFiringState::Aiming)
	{
		if (!Barrel) { return; }
		if (!ProjectileBlueprint) { return; }

		auto ProjectileLocation = Barrel->GetSocketLocation(FName("Projectile"));
		auto ProjectileRotation = Barrel->GetSocketRotation(FName("Projectile"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ProjectileLocation, ProjectileRotation);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		AmmoCount--;
	}
}

void UTankAimingComponent::ThrowFlame()
{
	if (!Barrel) { return; }
	if (!FlameThrowerBlueprint) { return; }
	if (!Fuel) { return; }

	if (Fuel->IsThereFuel())
	{
		auto FlameThrowerLocation = Barrel->GetSocketLocation(FName("FlameThrow"));
		auto FlameThrowerRotation = Barrel->GetSocketRotation(FName("FlameThrow"));
		auto FlameThrower = GetWorld()->SpawnActor<AFlameThrower>(FlameThrowerBlueprint, FlameThrowerLocation, FlameThrowerRotation);

		FlameThrower->FireFlame(FlameDistance);
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!Barrel) { return false; }
	FVector BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01);
}