// Copyright MKProductions

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


public:
	FTankDelegate OnDeath;
	//called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator, AActor * DamageCauser) override;

	//returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	//mainly for adding health when picking up health items on ground
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float HealthToAdd);

	//returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Armor")
	float GetArmorPercent() const;

	//mainly for adding health when picking up health items on ground
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddArmor(float ArmorToAdd);

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth; // Initialized in begin play

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingArmor = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentArmor; // Initialized in begin play
	
	virtual void BeginPlay() override;
};
