// Copyright MKProductions

#include "BattleTank.h"
#include "Mortar.h"


// Sets default values
AMortar::AMortar()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AMortar::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float AMortar::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{

	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		OnDeath.Broadcast();
	}
	
	return DamageToApply;
}

float AMortar::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}
