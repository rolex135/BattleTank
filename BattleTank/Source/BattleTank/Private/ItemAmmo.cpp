// Copyright MKProductions

#include "BattleTank.h"
#include "ItemAmmo.h"


// Sets default values
AItemAmmo::AItemAmmo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AItemAmmo::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AItemAmmo::OnOverlapBegin);
	AmmoAmountToAdd = rand() % (MaxAmmoToAdd - MinAmmoToAdd + 1) + MinAmmoToAdd;
}

void AItemAmmo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	CollisionMesh->DestroyComponent();
}

int32 AItemAmmo::GetAmmoAmountToAdd()
{
	return AmmoAmountToAdd;
}


