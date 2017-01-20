// Copyright MKProductions

#include "BattleTank.h"
#include "ItemFuel.h"


// Sets default values
AItemFuel::AItemFuel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AItemFuel::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AItemFuel::OnOverlapBegin);
	FuelAmountToAdd = rand() % (MaxFuelToAdd - MinFuelToAdd + 1) + MinFuelToAdd;
}


void AItemFuel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	CollisionMesh->DestroyComponent();
}

int32 AItemFuel::GetFuelAmountToAdd()
{
	return FuelAmountToAdd;
}

