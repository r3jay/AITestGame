// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePickup.h"

// Sets default values
ABasePickup::ABasePickup()
{
	PrimaryActorTick.bCanEverTick = false;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnBeginOverlap);
}

bool ABasePickup::CanPickup(AActor* OtherActor)
{
	return true;
}

void ABasePickup::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (CanPickup(OtherActor))
	{
		HandleCollision(OtherActor, SweepResult);
		HandlePostPickup();
	}
}

void ABasePickup::HandlePostPickup()
{
	Destroy();
}

void ABasePickup::HandleCollision(AActor* OtherActor, const FHitResult& SweepResult)
{
}
