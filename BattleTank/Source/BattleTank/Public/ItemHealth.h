// Copyright MKProductions

#pragma once

#include "Items.h"
#include "ItemHealth.generated.h"

UCLASS()
class BATTLETANK_API AItemHealth : public AItems
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemHealth();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int32 MaxHealthToAdd = 10;

	int32 MinHealthToAdd = 1;
};
