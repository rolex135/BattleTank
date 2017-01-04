// Copyright MKProductions

#include "BattleTank.h"
#include "MortarAIController.h"
#include "Mortar.h"
#include "TankAimingComponent.h"

AMortarAIController::AMortarAIController()
{
	FlamesOnDying = CreateDefaultSubobject<UParticleSystemComponent>(FName("Mortar Mesh"));
	FlamesOnDying->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FlamesOnDying->bAutoActivate = false;

	//TODO make flames work
}

void AMortarAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AMortarAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AIMortar = GetPawn();

	if (!(PlayerTank && AIMortar)) { return; }

	auto AimingComponent = AIMortar->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}

void AMortarAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossesedMortar = Cast<AMortar>(InPawn);
		if (!PossesedMortar) { return; }
		PossesedMortar->OnDeath.AddUniqueDynamic(this, &AMortarAIController::OnPossesedMortarDeath);
	}
}

void AMortarAIController::OnPossesedMortarDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}


