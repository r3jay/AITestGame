// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/MyActor.h"
#include "../../A_RicardoRodz.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	ClassType = AMyActor::StaticClass();
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	//Same as Bind in blueprint
	OnExampleVariable.AddDynamic(this, &AMyActor::TestFunction);

	//Same as Calling in Blueprint
	OnExampleVariable.Broadcast(this);
}

void AMyActor::TestFunction(AActor* Other)
{
	UE_LOG(Game, Warning, TEXT("Function called by delegate"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

