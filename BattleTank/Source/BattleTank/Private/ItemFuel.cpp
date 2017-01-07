// Copyright MKProductions

#include "BattleTank.h"
#include "ItemFuel.h"
#include "TankFuel.h"


// Sets default values
AItemFuel::AItemFuel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);

	SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/SpawningItems/FuelMesh"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}	
}

// Called when the game starts or when spawned
void AItemFuel::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AItemFuel::OnHit);
	FuelAmountToAdd = rand() % (MaxFuelToAdd - MinFuelToAdd + 1) + MinFuelToAdd;
}

void AItemFuel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Item Fuel"));
	UTankFuel Fuel;
	Fuel.SetFuelAmount(Fuel.GetFuelAmount() + FuelAmountToAdd);
	CollisionMesh->DestroyComponent();
	SphereVisual->DestroyComponent();
}

