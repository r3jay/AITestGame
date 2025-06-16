// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleWithInterfaces.h"
#include "../../A_RicardoRodz.h"

// Sets default values
AExampleWithInterfaces::AExampleWithInterfaces()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExampleWithInterfaces::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExampleWithInterfaces::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExampleWithInterfaces::BlueprintCallable()
{
	UE_LOG(Game, Warning, TEXT("In C++ BlueprintCallable"));
}

