// Copyright MKProductions

#include "BattleTank.h"
#include "WeaponComponent.h"
#include "Projectile.h"
#include "FlameThrower.h"
#include "IceBlast.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	AmmoCount = StartingAmmo;
}

void UWeaponComponent::SpawnCurrentWeaponAndLaunch(FVector FiringLocation, FRotator FiringRotation)
{
	if (GetCurrentWeapon() == ECurrentWeapon::Projectile)
	{
		auto Weapon = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, FiringLocation, FiringRotation);
		Weapon->Launch(GetCurrentWeaponLaunchSpeed());
		DecreaseOrAddAmmo(-1);
	}else if(GetCurrentWeapon() == ECurrentWeapon::IceBlast)
	{
		auto Weapon = GetWorld()->SpawnActor<AIceBlast>(IceBlastBlueprint, FiringLocation, FiringRotation);
		Weapon->Launch(GetCurrentWeaponLaunchSpeed());
		DecreaseOrAddAmmo(-1);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon not found"))
	}
}

void UWeaponComponent::SpawnFlameThrowerAndLaunch(FVector FiringLocation, FRotator FiringRotation)
{
	auto FlameThrower = GetWorld()->SpawnActor<AFlameThrower>(FlameThrowerBlueprint, FiringLocation, FiringRotation);
	FlameThrower->Launch(FlameThrowerLaunchSpeed);
}

void UWeaponComponent::DecreaseOrAddAmmo(int32 AmmoCountToDecrease)
{
	AmmoCount = GetAmmoCount() + AmmoCountToDecrease;
}

int32 UWeaponComponent::GetAmmoCount() const
{
	return AmmoCount;
}

ECurrentWeapon UWeaponComponent::GetCurrentWeapon() const
{
	return CurrentWeapon;
}

float UWeaponComponent::GetCurrentWeaponLaunchSpeed() const
{
	float CurrentWeaponLaunchSpeed = 0.f;
	switch (GetCurrentWeapon())
	{
	case ECurrentWeapon::Projectile:
		CurrentWeaponLaunchSpeed = ProjectileLaunchSpeed;
		break;
	case ECurrentWeapon::IceBlast:
		CurrentWeaponLaunchSpeed = IceBlastLaunchSpeed;
	default:
		break;
	}
	return CurrentWeaponLaunchSpeed;
}

void UWeaponComponent::SetCurrentWeapon(ECurrentWeapon WeaponToSet)
{
	CurrentWeapon = WeaponToSet;
}