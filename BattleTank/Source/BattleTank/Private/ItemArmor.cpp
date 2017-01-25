// Copyright MKProductions

#include "BattleTank.h"
#include "ItemArmor.h"


// Sets default values
AItemArmor::AItemArmor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AItemArmor::BeginPlay()
{
	MaxToAdd = MaxArmorToAdd;
	MinToAdd = MinArmorToAdd;
	Super::BeginPlay();
}
