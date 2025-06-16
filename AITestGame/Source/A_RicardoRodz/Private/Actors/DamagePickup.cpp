// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/DamagePickup.h"
#include "Kismet/GameplayStatics.h"

ADamagePickup::ADamagePickup()
{
    Damage = 2.0f;

    BoxCollision->SetWorldScale3D(FVector(1.6f, 1.6f, 1.6f));

    ParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
    ParticleSystem->SetupAttachment(BoxCollision);
    ParticleSystem->SetRelativeLocation(FVector(0.0f, 0.0f, -30.0f));
    ParticleSystem->SetWorldScale3D(FVector(0.4f, 0.4f, 0.25f));
}

void ADamagePickup::HandleCollision(AActor* OtherActor, const FHitResult& SweepResult)
{
    Super::HandleCollision(OtherActor, SweepResult); 

    if (OtherActor && OtherActor != this)
    {
        UGameplayStatics::ApplyDamage(OtherActor, Damage, GetInstigatorController(), this, NULL);
    }
}

void ADamagePickup::HandlePostPickup()
{
}