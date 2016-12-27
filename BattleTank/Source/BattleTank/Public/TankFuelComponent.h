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
	UTankFuelComponent();

	UFUNCTION(BlueprintCallable, Category = "Fuel")
	int32 GetFuelAmount() const;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankFuel* FuelToSet);

	virtual void BeginPlay() override;

	void SetFuelAmount(int32 FuelAmount);

	EFuelState GetFuelState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFuelState FuelState = EFuelState::Full;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingFuel = 2000;

	UPROPERTY(VisibleAnywhere, Category = "Fuel")
	int32 CurrentFuel; // Initialized in begin play

	UTankFuel* Fuel = nullptr;
	
	virtual void UTankFuelComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

};
