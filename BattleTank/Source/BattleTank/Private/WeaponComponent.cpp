// Copyright MKProductions

#include "BattleTank.h"
#include "WeaponComponent.h"


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

void UWeaponComponent::CurrentWeapon()
{
	return ProjectileBlueprint;
}
