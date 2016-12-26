// Copyright MKProductions

#include "BattleTank.h"
#include "FlameThrower.h"


// Sets default values
AFlameThrower::AFlameThrower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(false);

	FireBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Fire Blast"));
	FireBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ImpactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	ImpactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ImpactBlast->bAutoActivate = false;

	FlameMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Flame Movement"));
	FlameMovement->bAutoActivate = false;

	ExplosionForce = CreateDefaultSubobject<URadialForceComponent>(FName("Explosion Force"));
	ExplosionForce->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AFlameThrower::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AFlameThrower::OnHit);
}

void AFlameThrower::FireFlame(float Speed)
{
	FlameMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	FlameMovement->Activate();
}

void AFlameThrower::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	FireBlast->Deactivate();
	ImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(
		this, FlameThrowerDamage, GetActorLocation(), ExplosionForce->Radius, UDamageType::StaticClass(),
		TArray<AActor*>());

	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AFlameThrower::OnTimerExpire, DestroyDelay, false);
}

void AFlameThrower::OnTimerExpire()
{
	Destroy();
}