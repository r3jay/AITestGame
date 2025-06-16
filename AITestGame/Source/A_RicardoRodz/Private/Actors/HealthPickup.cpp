// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthPickup.h"
#include "Actors/PickupInterface.h"


AHealthPickup::AHealthPickup()
{
    Damage = -1.5f; 

    if (BoxCollision)
    {
        BoxCollision->SetWorldScale3D(FVector(1.5f, 1.5f, 2.0f));
    }

    if (ParticleSystem) 
    {
        ParticleSystem->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
        ParticleSystem->SetWorldScale3D(FVector(0.5f, 0.5f, 0.7f));
    }
}

//bool AHealthPickup::CanPickupHealth()
//{
//    return false;
//}

bool AHealthPickup::CanPickup(AActor* OtherActor)
{
    if (OtherActor)
    {
        IPickupInterface* PickupActor = Cast<IPickupInterface>(OtherActor);
        if (PickupActor && PickupActor->CanPickupHealth())
        {
            return true;
        }
    }
    return false;
}

void AHealthPickup::HandlePostPickup()
{
    Destroy();
}