// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DamagePickup.h"
//#include "Actors/PickupInterface.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API AHealthPickup : public ADamagePickup //, public IPickupInterface
{
	GENERATED_BODY()
public:
		AHealthPickup();

		//virtual bool CanPickupHealth() override;

		virtual bool CanPickup(AActor* OtherActor) override;

		virtual void HandlePostPickup() override;
};