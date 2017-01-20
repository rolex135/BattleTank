// Copyright MKProductions

#include "BattleTank.h"
#include "WeaponComponent.h"
#include "Projectile.h"
#include "IceBlast.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called every frame
void UWeaponComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	AmmoCount = StartingAmmo;
}

void UWeaponComponent::SpawnCurrentWeaponAndLaunch(FVector FiringLocation, FRotator FiringRotation, float LaunchSpeed)
{

	if (GetCurrentWeapon() == ECurrentWeapon::MainWeapon)
	{
		auto Weapon = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, FiringLocation, FiringRotation);
		Weapon->Launch(LaunchSpeed);
		DecreaseOrAddAmmo(-1);
	}else if(GetCurrentWeapon() == ECurrentWeapon::SecondaryWeapon)
	{
		auto Weapon = GetWorld()->SpawnActor<AIceBlast>(IceBlastBlueprint, FiringLocation, FiringRotation);
		Weapon->Launch(LaunchSpeed);
		DecreaseOrAddAmmo(-1);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon not found"))
	}
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

void UWeaponComponent::SetCurrentWeapon(ECurrentWeapon WeaponToSet)
{
	CurrentWeapon = WeaponToSet;
}