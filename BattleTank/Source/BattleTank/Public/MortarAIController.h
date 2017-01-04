// Copyright MKProductions

#pragma once

#include "AIController.h"
#include "MortarAIController.generated.h"

/**
 * Responsible for Controlling AI Mortars
 */
UCLASS()
class BATTLETANK_API AMortarAIController : public AAIController
{
	GENERATED_BODY()

private:
	AMortarAIController();

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* FlamesOnDying = nullptr;

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void OnPossesedMortarDeath();
};
