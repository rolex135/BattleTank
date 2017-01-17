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
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingFuel = 20000;

	UFUNCTION(BlueprintCallable, Category = "Fuel")
	int32 GetFuelAmount() const;

	UFUNCTION(BlueprintCallable, Category = "Fuel")
	void SetFuelAmount(int32 FuelAmount);

	bool IsThereFuel() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 FuelCount;

	virtual void BeginPlay() override;
};
