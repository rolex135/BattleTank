// Copyright MKProductions

#pragma once

#include "Items.h"
#include "ItemArmor.generated.h"

UCLASS()
class BATTLETANK_API AItemArmor : public AItems
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemArmor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	int32 MaxArmorToAdd = 100;

	int32 MinArmorToAdd = 1;
};
