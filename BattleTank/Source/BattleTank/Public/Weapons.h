// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "Weapons.generated.h"

UCLASS()
class BATTLETANK_API AWeapons : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapons();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Launch(float Speed);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	float DestroyDelay;

	float Damage;

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Component")
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();

};