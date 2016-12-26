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

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float FlameThrowerDamage = 5.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 0.5f;

	UProjectileMovementComponent* FlameMovement = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Component")
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();
};
