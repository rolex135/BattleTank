// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "ItemAmmo.generated.h"

UCLASS()
class BATTLETANK_API AItemAmmo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemAmmo();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	int32 GetAmmoAmountToAdd();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 AmmoAmountToAdd;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* CollisionMesh = nullptr;

	int32 MaxAmmoToAdd = 10;
	
	int32 MinAmmoToAdd = 1;

	UFUNCTION(BlueprintCallable, Category = "Action")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
