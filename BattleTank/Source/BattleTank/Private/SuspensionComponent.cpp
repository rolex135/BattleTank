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
	if (!LeftBack || !LeftMiddle || !LeftFront || !RightBack || !RightMiddle || !RightFront) { return; }

	AddForceToSuspension(LeftBack);
	AddForceToSuspension(LeftMiddle);
	AddForceToSuspension(LeftFront);

	AddForceToSuspension(RightBack);
	AddForceToSuspension(RightMiddle);
	AddForceToSuspension(RightFront);
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

FVector USuspensionComponent::GetSuspensionLocation(UTankSuspension* Suspension)
{
	FVector SuspensionLocation = Suspension->GetComponentLocation();

	return SuspensionLocation;
}

FHitResult USuspensionComponent::GetResultWhenOnGround(UTankSuspension* Suspension)
{
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	GetWorld()->LineTraceSingleByObjectType(
		HitResult,
		GetSuspensionLocation(Suspension),
		GetMaxSuspensionZLocation(Suspension),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic),
		TraceParameters
	);

	return HitResult;
}


FVector USuspensionComponent::GetMaxSuspensionZLocation(UTankSuspension* Suspension)
{
	FVector SuspensionLocation = GetSuspensionLocation(Suspension);
	FRotator SuspensionRotation = FRotator(-90, 0, 0);
	return SuspensionLocation + SuspensionRotation.Vector() * Suspension->GetMaxZ();
}

void USuspensionComponent::AddForceToSuspension(UTankSuspension* Suspension)
{
	if (!Suspension) { return; }

	auto HitResult = GetResultWhenOnGround(Suspension);
	auto Ground = HitResult.TraceEnd;
	auto Susp = HitResult.TraceStart;
	auto DistanceBetweenGround = HitResult.Normal;
	auto S = HitResult.Distance;

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	float DistanceForSuspension = FMath::Clamp<float>(S, Suspension->GetMinZ(), Suspension->GetMaxZ());

	FVector NewLocationForSuspension = FVector(0.f, 0.f, S);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *NewLocationForSuspension.ToString())

	if (DistanceBetweenGround.Z < 1.f){
		//Suspension->SetRelativeLocation(NewLocationForSuspension);
		//Suspension->AddRelativeLocation(FVector(0, 0, 0.5f));
		Suspension->SetRelativeLocation(FVector(0, 0, 50.f));
	}

}
 
