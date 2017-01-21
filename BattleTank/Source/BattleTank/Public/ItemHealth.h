// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "ItemHealth.generated.h"

UCLASS()
class BATTLETANK_API AItemHealth : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemHealth();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	int32 GetHealthAmountToAdd();

private:
	UPROPERTY(VisibleAnywhere, Category = "Setup")
	int32 HealthAmountToAdd;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* CollisionMesh = nullptr;

	int32 MaxHealthToAdd = 10;

	int32 MinHealthToAdd = 1;

	UFUNCTION(BlueprintCallable, Category = "Action")
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	
};
