// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class BATTLETANK_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	int32 GetAmountToAdd();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	int32 AmountToAdd;

	UPROPERTY(VisibleAnywhere, Category = "Setup")
	UStaticMeshComponent* CollisionMesh = nullptr;

	int32 MaxToAdd;

	int32 MinToAdd;

	UFUNCTION(BlueprintCallable, Category = "Action")
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
