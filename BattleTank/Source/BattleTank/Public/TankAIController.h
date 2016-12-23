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
	
protected:
	//How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 4000.f;

private:

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void OnPossesedTankDeath();

};
