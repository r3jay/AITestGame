// Fill out your copyright notice in the Description page of Project Settings.


#include "Examples/ExampleDefaultPawn.h"
#include "../../A_RicardoRodz.h"
#include "GameFramework/PlayerInput.h"//For our mapping
#include "EngineUtils.h"
#include "Examples/ExampleWithInterfaces.h"


// Sets default values
AExampleDefaultPawn::AExampleDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(Game, Error, TEXT("Actor's name %s"), *GetName());
	float MyFloat = 3.21f;
	int32 MyInt = 2;
	UE_LOG(Game, Log, TEXT("int is %d and a float is %f"), MyInt, MyFloat);
	UE_LOG(Game, Warning, TEXT("Velocity is %s"), *GetVelocity().ToString());
}

// Called when the game starts or when spawned
void AExampleDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	//UpCast
	AActor* ParentPointer = this;

	//Downcast
	AExampleDefaultPawn* ChildPointer = Cast<AExampleDefaultPawn>(ParentPointer);

	if (ChildPointer) 
	{
		UE_LOG(Game, Log, TEXT("Success!"));
	}
	else 
	{
		UE_LOG(Game, Error, TEXT("This class is null!"));
	}

	for (TActorIterator<AExampleWithInterfaces> itr(GetWorld()); itr; ++itr)
	{
		ParentPointer = *itr;

		//How to use interfaces
		UExampleInterface* U = Cast<UExampleInterface>(ParentPointer);
		if (U) 
		{
			//U->blue
			UE_LOG(Game, Error, TEXT("I AM U"));
		}

		IExampleInterface* I = Cast<IExampleInterface>(ParentPointer);
		if (I)
		{
			I->BlueprintCallable();
			UE_LOG(Game, Error, TEXT("I AM I"));
		}
	}
}

// Called every frame
void AExampleDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AExampleDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Test_Spawn", EKeys::SpaceBar));
	PlayerInputComponent->BindAction("Test_Spawn", EInputEvent::IE_Pressed, this, &AExampleDefaultPawn::SpawnObject);
}

void AExampleDefaultPawn::SpawnObject()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetController();
	SpawnParams.Instigator = this;
	GetWorld()->SpawnActor<AActor>(ClassToSpawn, GetTransform(), SpawnParams);
}

