// Copyright MKProductions

#pragma once

#include "TankFuel.h"
#include "TankFuelActor.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATankFuelActor : public AActor
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Fuel")
		int32 GetFuelAmount() const;

	UFUNCTION(BlueprintCallable, Category = "Fuel")
		void SetFuelAmount(int32 FuelAmount);

	bool IsThereFuel();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingFuel = 20000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 FuelCount;

	virtual void BeginPlay() override;
};