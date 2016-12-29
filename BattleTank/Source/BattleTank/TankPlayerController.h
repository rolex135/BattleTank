// Copyright MKProductions

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward declarations
class UTankAimingComponent;
class UTankFuelComponent;
class UTankFuel;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundFuelComponent(UTankFuelComponent* FuelCompRef);

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundFuel(UTankFuel* FuelRef);

private:
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void OnPossesedTankDeath();

	//Start the tank moving the barrel so that a shot would it where
	//cross hair intersects the world
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

};
