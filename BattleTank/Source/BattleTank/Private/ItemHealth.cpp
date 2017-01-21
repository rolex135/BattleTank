// Copyright MKProductions

#include "BattleTank.h"
#include "ItemHealth.h"


// Sets default values
AItemHealth::AItemHealth()
{
	PrimaryActorTick.bCanEverTick = false;
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AItemHealth::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AItemHealth::OnOverlapBegin);
	HealthAmountToAdd = rand() % (MaxHealthToAdd - MinHealthToAdd + 1) + MinHealthToAdd;
}

void AItemHealth::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CollisionMesh->DestroyComponent();
}

int32 AItemHealth::GetHealthAmountToAdd()
{
	return HealthAmountToAdd;
}