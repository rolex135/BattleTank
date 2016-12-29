// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "TankFuelComponent.generated.h"

// Enum for fuel state
UENUM()
enum class EFuelState : uint8
{
	Full,
	HalfFull,
	Empty
};

class UTankFuel;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankFuelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankFuel* FuelToSet);

	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool IsFlameThrowerActive = false;

	EFuelState GetFuelState() const;

	void TankMovingBurnFuel();

	void TankFlameThrowerBurnFuel();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFuelState FuelState = EFuelState::HalfFull;

private:
	UTankFuelComponent();

	UTankFuel* Fuel;

	FVector TankPosition;

	//UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//int32 FuelCount = 2000;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
