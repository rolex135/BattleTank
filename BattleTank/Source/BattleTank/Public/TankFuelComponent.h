// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "TankFuelComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankFuelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankFuelComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	int32 GetFuelAmount() const;

	void SetFuelAmount(int32 FuelAmount);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingFuel = 2000;

	UPROPERTY(VisibleAnywhere, Category = "Fuel")
	int32 CurrentFuel; // Initialized in begin play
	
};
