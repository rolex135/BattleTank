// Copyright MKProductions

#pragma once

#include "GameFramework/Actor.h"
#include "WeaponInterface.h"
#include "IceBlast.generated.h"

UCLASS()
class BATTLETANK_API AIceBlast : public AActor, public IWeaponInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AIceBlast();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
