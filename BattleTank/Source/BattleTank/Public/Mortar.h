// Copyright MKProductions

#pragma once

#include "GameFramework/Pawn.h"
#include "Mortar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMortarDelegate);

UCLASS()
class BATTLETANK_API AMortar : public APawn
{
	GENERATED_BODY()

public:
	FMortarDelegate OnDeath;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator, AActor * DamageCauser) override;

	//returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

private:
	AMortar();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 50;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth; // Initialized in begin play

	virtual void BeginPlay() override;
		
};
