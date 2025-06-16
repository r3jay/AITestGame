// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVariableDelegate, AActor*, OtherActor);

UCLASS()
class A_RICARDORODZ_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Read Only
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variable|ReadOnly")
		bool VisibleAnywhere;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		uint8 VisibleDefaultsOnly;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Variable|ReadOnly")
		int32 VisibleInstanceOnlyOdd;
	UPROPERTY(VisibleInstanceOnly, Category = "Variable|ReadOnly")
		int64 VisibleInstanceOnly;

	//Read Write
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ReadWrite")
		float EditAnywhere;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
		FName EditDefaultsOnlyOdd;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Variable|ReadWrite")
		FString EditInstanceOnlyOdd;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Variable|ReadWrite")
		FText EditDefaultsOnly;
	UPROPERTY(EditInstanceOnly, Category = "Variable|ReadWrite")
		FVector EditInstanceOnly;

	//Class Reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable|ClassRef")
		TSubclassOf<AActor> ClassType;

	//Delegate / Event Dispatcher
	//Creating Variable
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Variable")
	FVariableDelegate OnExampleVariable;

private:
	UFUNCTION()
		void TestFunction(AActor* Other);
};
