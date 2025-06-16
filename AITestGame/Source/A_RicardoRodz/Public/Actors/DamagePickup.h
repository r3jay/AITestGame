// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BasePickup.h"
#include "Particles/ParticleSystemComponent.h"
#include "DamagePickup.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API ADamagePickup : public ABasePickup
{
	GENERATED_BODY()
	
public:
	ADamagePickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effects")
		UParticleSystemComponent* ParticleSystem;

	virtual void HandleCollision(AActor* OtherActor, const FHitResult& SweepResult) override;

	virtual void HandlePostPickup() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
		float Damage;
};
