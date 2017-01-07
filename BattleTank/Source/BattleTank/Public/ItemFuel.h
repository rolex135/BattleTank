// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "ItemFuel.generated.h"

/*
Spawnable actor to world.
Adds fuel to tank if tank drives over it
*/
UCLASS()
class BATTLETANK_API AItemFuel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemFuel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* SphereVisual = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 FuelAmountToAdd;

	int32 MaxFuelToAdd = 400;
	
	int32 MinFuelToAdd = 50;

	UFUNCTION(BlueprintCallable, Category = "Action")
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse, const FHitResult& Hit);
};
