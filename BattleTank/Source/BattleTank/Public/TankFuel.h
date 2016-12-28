// Copyright MKProductions

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankFuel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankFuel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = "Fuel")
	int32 CurrentFuel; // Initialized in begin play

	virtual void BeginPlay() override;
	
private:	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingFuel = 2000;

	
};
