// Copyright MKProductions
#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
class UTankFuelComponent;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet, UTankFuelComponent* FuelToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendTurnLeft(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveBackward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void TankMoving();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	UTankTrack* LeftTrack = nullptr;

	UTankTrack* RightTrack = nullptr;

	UTankFuelComponent* FuelComponent = nullptr;

	FVector TankPosition; //Initialized in beginplay

	// Called from the path finding logic by the AI controllers
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
};
