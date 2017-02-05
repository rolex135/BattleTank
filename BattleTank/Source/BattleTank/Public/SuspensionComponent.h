// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "SuspensionComponent.generated.h"

class UTankSuspension;

/* Responsible for suspensions and adding Force to them*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API USuspensionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USuspensionComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankSuspension* LeftBackToSet, UTankSuspension* LeftMiddleToSet, UTankSuspension* LeftFrontToSet, UTankSuspension* RightBackToSet, UTankSuspension* RightMiddleToSet, UTankSuspension* RightFrontToSet);

private:
	UTankSuspension* LeftBack = nullptr;

	UTankSuspension* LeftMiddle = nullptr;

	UTankSuspension* LeftFront = nullptr;

	UTankSuspension* RightBack = nullptr;

	UTankSuspension* RightMiddle = nullptr;

	UTankSuspension* RightFront = nullptr;

	FVector GetSuspensionLocation(UTankSuspension* Suspension);
	
	FVector GetMaxSuspensionZLocation(UTankSuspension* Suspension);

	void AddForceToSuspension(UTankSuspension* Suspension);

	FHitResult GetResultWhenOnGround(UTankSuspension* Suspension);
};
