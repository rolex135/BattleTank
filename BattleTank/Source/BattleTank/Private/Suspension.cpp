// Copyright MKProductions

#include "BattleTank.h"
#include "Suspension.h"


// Sets default values
ASuspension::ASuspension()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
float ASuspension::GetMaxZ()
{
	return MaxZ;
}
