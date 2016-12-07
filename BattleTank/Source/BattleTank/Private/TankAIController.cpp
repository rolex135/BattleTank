// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"
#include "../Public/TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetAIControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing: %s"), *ControlledTank->GetName());
	}
}

ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
