// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BasePickup.generated.h"

UCLASS(Abstract)
class A_RICARDORODZ_API ABasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
		UBoxComponent* BoxCollision;

	UFUNCTION(BlueprintPure)
		virtual bool CanPickup(AActor* OtherActor);

	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		virtual void HandlePostPickup();

	UFUNCTION(BlueprintCallable, Category = "Pickup")
		virtual void HandleCollision(AActor* OtherActor, const FHitResult& SweepResult);
};
