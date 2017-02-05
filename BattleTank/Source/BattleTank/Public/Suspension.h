// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "Suspension.generated.h"

UCLASS()
class BATTLETANK_API ASuspension : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASuspension();

	float GetMaxZ();

private:

	float MaxZ = 50.f;

	float MinZ = 0.f;

	
};
