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

	UFUNCTION(BlueprintCallable, Category = "Setup")
	int32 GetFuelAmountToAdd();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* CollisionMesh = nullptr;
	
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 FuelAmountToAdd;

	int32 MaxFuelToAdd = 20000;
	
	int32 MinFuelToAdd = 50;

	UFUNCTION(BlueprintCallable, Category = "Action")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
