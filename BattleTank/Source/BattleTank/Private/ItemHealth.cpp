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
	MaxToAdd = MaxHealthToAdd;
	MinToAdd = MinHealthToAdd;
	Super::BeginPlay();
}
