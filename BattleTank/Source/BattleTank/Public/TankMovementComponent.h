// Copyright MKProductions
#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
class UTankFuel;
class UTankSuspension;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankFuel* FuelToSet, UTankSuspension* LeftBackToSet, UTankSuspension* LeftMiddleToSet, UTankSuspension* LeftFrontToSet, UTankSuspension* RightBackToSet, UTankSuspension* RightMiddleToSet, UTankSuspension* RightFrontToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveBackward(float Throw);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UTankSuspension* LeftBack = nullptr;

	UTankSuspension* LeftMiddle = nullptr;

	UTankSuspension* LeftFront = nullptr;

	UTankSuspension* RightBack = nullptr;

	UTankSuspension* RightMiddle = nullptr;

	UTankSuspension* RightFront = nullptr;

	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;

	UTankFuel* Fuel = nullptr;

	// Called from the path finding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
