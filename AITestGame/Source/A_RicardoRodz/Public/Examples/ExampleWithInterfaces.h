// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Examples/ExampleInterface.h"

#include "ExampleWithInterfaces.generated.h"

UCLASS()
class A_RICARDORODZ_API AExampleWithInterfaces : public AActor, public IExampleInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExampleWithInterfaces();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//IExampleInterface
	void BlueprintCallable() override;
	//IExampleInterface
};
