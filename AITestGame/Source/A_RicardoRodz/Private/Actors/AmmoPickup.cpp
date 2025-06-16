// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AmmoPickup.h"
#include "Actors/BasePlayer.h"
#include "Actors/Rifle.h"

AAmmoPickup::AAmmoPickup()
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->SetupAttachment(BoxCollision);
	if (BoxCollision)
	{
		BoxCollision->SetWorldScale3D(FVector(2.0f, 2.0f, 1.625f));
	}
	if (PickupMesh)
	{
		PickupMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -22.0f));
		PickupMesh->SetWorldScale3D(FVector(0.6f, 0.525f, 0.45f));
	}
	Damage = 0;
}

void AAmmoPickup::HandleCollision(AActor* OtherActor, const FHitResult& SweepResult)
{
	ABasePlayer* Player = Cast<ABasePlayer>(OtherActor);
	if (Player)
	{
		ARifle* Weapon = Cast<ARifle>(Player->GetWeapon());
		if (Weapon)
		{
			Weapon->IncreaseMaxAmmo();
		}
	}
}