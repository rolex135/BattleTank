// Copyright MKProductions

#include "BattleTank.h"
#include "Items.h"


// Sets default values
AItems::AItems()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AItems::OnOverlapBegin);
	AmountToAdd = rand() % (MaxToAdd - MinToAdd + 1) + MinToAdd;
}

void AItems::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CollisionMesh->DestroyComponent();
}

int32 AItems::GetAmountToAdd()
{
	return AmountToAdd;
}


