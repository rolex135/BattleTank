// Copyright MKProductions

#include "BattleTank.h"
#include "WeaponInterface.h"


// This function does not need to be modified.
UWeaponInterface::UWeaponInterface(const class FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

// Add default functionality here for any IWeaponInterface functions that are not pure virtual.

void IWeaponInterface::Test()
{
	UE_LOG(LogTemp, Error, TEXT("UWeaponInterface"));
}
