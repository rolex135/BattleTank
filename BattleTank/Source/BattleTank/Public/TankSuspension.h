// Copyright MKProductions

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankSuspension.generated.h"

/**
 * TankSuspension is used to set smooth driving for tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankSuspension : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	float MaxZ = 1.f;

	float MinZ = -1.f;

};
