// Copyright MKProductions

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "WeaponComponent.h"
#include "../Public/TankAIController.h"
#include "Tank.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AITank = GetPawn();

	if (!(PlayerTank && AITank)) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = AITank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	//Change weapons based on distance between AI and player
	float DistanceBetweenPlayer = (PlayerTank->GetActorLocation() - AITank->GetActorLocation()).Size();
	auto WeaponComponent = AITank->FindComponentByClass<UWeaponComponent>();
	if (DistanceBetweenPlayer < WeaponComponent->GetCurrentWeaponLaunchSpeed() && WeaponComponent->GetCurrentWeapon() != ECurrentWeapon::IceBlast)
	{
		WeaponComponent->SetCurrentWeapon(ECurrentWeapon::IceBlast);
		UE_LOG(LogTemp, Warning, TEXT("Changed to Iceblast at: %f"), DistanceBetweenPlayer);
	}
	else if(DistanceBetweenPlayer > WeaponComponent->GetProjectileLaunchSpeed() && WeaponComponent->GetCurrentWeapon() != ECurrentWeapon::Projectile)
	{
		WeaponComponent->SetCurrentWeapon(ECurrentWeapon::Projectile);
		UE_LOG(LogTemp, Warning, TEXT("Changed to Projectile at: %f"), DistanceBetweenPlayer);
	}
	else
	{
		//
	}

	//Fire if aim found
	if (DistanceBetweenPlayer < WeaponComponent->GetFlameThrowerLaunchSpeed())
	{
		AimingComponent->ThrowFlame();
	}

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
			AimingComponent->Fire();
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedTank = Cast<ATank>(InPawn);
		if (!PossesedTank) { return; }

		//Subscribe our local method to the tank's death event
		PossesedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossesedTankDeath);
	}
}

void ATankAIController::OnPossesedTankDeath()
{
	if (!GetPawn()) { return; }

	GetPawn()->DetachFromControllerPendingDestroy();
}

