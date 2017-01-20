// Copyright MKProductions

#include "BattleTank.h"
#include "IceBlast.h"


// Sets default values
AIceBlast::AIceBlast()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIceBlast::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIceBlast::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

