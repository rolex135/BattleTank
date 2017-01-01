// Copyright MKProductions

#include "BattleTank.h"
#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AWeapon::OnHit);
}

void AWeapon::LaunchWeapon(float Speed)
{
	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}

void AWeapon::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
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
	GetWorld()->GetTimerManager().SetTimer(Timer, this, &AWeapon::OnTimerExpire, DestroyDelay, false);
}

void AWeapon::OnTimerExpire()
{
	Destroy();
}
