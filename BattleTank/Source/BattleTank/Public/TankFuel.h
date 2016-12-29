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
	UFUNCTION(BlueprintCallable, Category = "Fuel")
	int32 GetFuelAmount() const;

	void SetFuelAmount(int32 FuelAmount);

	bool IsThereFuel();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingFuel = 2000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 FuelCount;

	virtual void BeginPlay() override;
};
