// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward declaration
class UTankBarrel;
class UTankTurret;

// Holds barrel's properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);


private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	bool bHaveAimSolution;

	void MoveBarrelTowards(FVector AimDirection);

	void RotateTurretTowards(FVector AimDirection);
};
