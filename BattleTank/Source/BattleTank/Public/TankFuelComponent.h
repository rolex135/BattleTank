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

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankFuelComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankFuel* FuelToSet);

	UFUNCTION(BlueprintCallable, Category = "Fuel")
	int32 GetFuelAmount() const;

	EFuelState GetFuelState() const;

	void SetFuelAmount(int32 FuelAmount);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFuelState FuelState = EFuelState::Full;

private:
	UTankFuelComponent();

	UTankFuel* Fuel = nullptr;
	
	virtual void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
