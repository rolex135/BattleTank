// Copyright MKProductions

#include "BattleTank.h"
#include "TankSuspension.h"
#include "SuspensionComponent.h"


// Sets default values for this component's properties
USuspensionComponent::USuspensionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void USuspensionComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USuspensionComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

void USuspensionComponent::Initialize(UTankSuspension* LeftBackToSet, UTankSuspension* LeftMiddleToSet, UTankSuspension* LeftFrontToSet, UTankSuspension* RightBackToSet, UTankSuspension* RightMiddleToSet, UTankSuspension* RightFrontToSet)
{
	LeftBack = LeftBackToSet;
	LeftMiddle = LeftMiddleToSet;
	LeftFront = LeftFrontToSet;
	RightBack = RightBackToSet;
	RightMiddle = RightMiddleToSet;
	RightFront = RightFrontToSet;
}

float USuspensionComponent::GetSuspensionZLocation(UTankSuspension* Suspension)
{
	FVector SuspensionLocation = Suspension->GetComponentLocation();

	return SuspensionLocation.Z;
}

void USuspensionComponent::AddForceToSuspension(UTankSuspension* Suspension)
{
	float SuspensionZLocation = GetSuspensionZLocation(Suspension);

}

