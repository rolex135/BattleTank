// Copyright MKProductions

#include "BattleTank.h"
#include "FlameThrower.h"


// Sets default values
AFlameThrower::AFlameThrower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	FireBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Fire Blast"));
	FireBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	FlameMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Flame Movement"));
	FlameMovement->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AFlameThrower::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFlameThrower::FireFlame(float Speed)
{
	FlameMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	FlameMovement->Activate();
	FlameMovement->DestroyComponent();
}