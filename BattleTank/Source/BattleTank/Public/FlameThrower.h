// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "FlameThrower.generated.h"

UCLASS()
class BATTLETANK_API AFlameThrower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlameThrower();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void FireFlame(float Speed);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* FireBlast = nullptr;

	UProjectileMovementComponent* FlameMovement = nullptr;

	float DestroyDelay = 2.f;
	
};
