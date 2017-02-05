// Copyright MKProductions

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankSuspension.generated.h"

/**
 * TankSuspension is used to set smooth driving for tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankSuspension : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UTankSuspension();

	float GetMaxZ();

	float GetMinZ();

private:

	float MaxZ = 50.f;

	float MinZ = 0.f;

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	//Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000.f;//assume 40 tonne tank and 1g acceleration

private:

	UFUNCTION(BlueprintCallable, Category = "Input")
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			FVector NormalImpulse, const FHitResult& Hit);

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	void DriveTrack();

	float CurrentThrottle = 0;

};
