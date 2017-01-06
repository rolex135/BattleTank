// Copyright MKProductions

#pragma once

#include "Components/ActorComponent.h"
#include "ItemSpawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UItemSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemSpawnComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SpawnItem(FVector LocationToSpawn);

	void SpawnRandomItemActor(FVector LocationToSpawn);
};