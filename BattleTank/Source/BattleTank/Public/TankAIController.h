// Copyright MKProductions

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * Responsible for Controlling AI Tanks
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	//How close can the AI tank get
	float AcceptanceRadius = 3000.f;
};
