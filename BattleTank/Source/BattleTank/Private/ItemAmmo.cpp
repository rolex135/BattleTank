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
	CollisionMesh->OnComponentHit.AddDynamic(this, &AItemAmmo::OnHit);
	AmmoAmountToAdd = rand() % (MaxAmmoToAdd - MinAmmoToAdd + 1) + MinAmmoToAdd;
}

void AItemAmmo::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Item ammo"));
	CollisionMesh->DestroyComponent();
}


