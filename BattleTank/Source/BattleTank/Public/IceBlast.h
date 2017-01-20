// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "IceBlast.generated.h"

UCLASS()
class BATTLETANK_API AIceBlast : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIceBlast();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Launch(float Speed);

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float DestroyDelay = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ProjectileDamage = 100.f;

	UProjectileMovementComponent* ProjectileMovement = nullptr;

	UFUNCTION(BlueprintCallable, Category = "Component")
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerExpire();
	
	
};
