// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleFunctions.h"
#include "../../A_RicardoRodz.h"


// Sets default values
AExampleFunctions::AExampleFunctions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; //Lower case b is a bitfield
	//PrimaryActorTick.bStartWithTickEnabled = false;
}

// Called when the game starts or when spawned
void AExampleFunctions::BeginPlay()
{
	Super::BeginPlay();
	BlueprintCallable();
	BlueprintImplementableEvent();
	BlueprintNativeEvent();
}
//void BlueprintImplementableEvent() 
//{
//	UE_LOG(Game, Error, TEXT("BlueprintImplementableEvent"));
//}
void AExampleFunctions::BlueprintCallable()
{
	UE_LOG(Game, Error, TEXT("BlueprintCallable"));
}
void AExampleFunctions::BlueprintNativeEvent_Implementation()
{
	UE_LOG(Game, Warning, TEXT("BlueprintNativeEvent_Implementation"));
}
float AExampleFunctions::PureFunction() const
{
	return 5.42f;
}
// Called every frame
void AExampleFunctions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

