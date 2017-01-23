// Copyright MKProductions

#include "BattleTank.h"
#include "Weapons.h"


// Sets default values
AWeapons::AWeapons()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AWeapons::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AWeapons::OnHit);
}

void AWeapons::Launch(float LaunchSpeed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * LaunchSpeed);
	ProjectileMovement->Activate();
}

void AWeapons::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	LaunchBlast->Deactivate();
	ImpactBlast->Activate();
	ExplosionForce->FireImpulse();
	SetRootComponent(ImpactBlast);
	CollisionMesh->DestroyComponent();

	UGameplayStatics::ApplyRadialDamage(
		this, Damage, GetActorLocation(), ExplosionForce->Radius, UDamageType::StaticClass(),
		TArray<AActor*>());

	FTimerHandle Timer;
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AWeapons::OnTimerExpire, DestroyDelay, false);
}

void AWeapons::OnTimerExpire()
{
	Destroy();
}