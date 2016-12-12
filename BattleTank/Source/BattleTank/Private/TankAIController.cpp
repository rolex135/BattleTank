// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "../Public/TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		//TODO Move towards the player

		AimAtPlayer();
		
		//TODO Fire if ready
	}
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::AimAtPlayer()
{
	GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}
