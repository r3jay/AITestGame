// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/HealthPickup.h"
#include "AmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API AAmmoPickup : public AHealthPickup
{
	GENERATED_BODY()
public:

	AAmmoPickup();

	virtual void HandleCollision(AActor* OtherActor, const FHitResult& SweepResult) override;

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMeshComponent* PickupMesh;
};
