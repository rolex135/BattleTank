// Copyright MKProductions

#include "BattleTank.h"
#include "WeaponComponent.h"
#include "Projectile.h"


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

UClass* UWeaponComponent::CurrentWeapon()
{
	return ProjectileBlueprint;
}

void UWeaponComponent::SetAmmoCount(int32 AmmoCountToSet)
{
	AmmoCount = AmmoCountToSet;
}

int32 UWeaponComponent::GetAmmoCount()
{
	return AmmoCount;
}