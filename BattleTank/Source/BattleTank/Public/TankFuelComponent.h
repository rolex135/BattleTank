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
	UPROPERTY(BlueprintReadWrite, Category = "State")
	bool IsFlameThrowerActive = false;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankFuel* FuelToSet);

	EFuelState GetFuelState() const;

	void TankMovingBurnFuel();

	void TankFlameThrowerBurnFuel();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFuelState FuelState = EFuelState::HalfFull;

private:
	UTankFuelComponent();

	FVector TankPosition;

	UTankFuel* Fuel;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
