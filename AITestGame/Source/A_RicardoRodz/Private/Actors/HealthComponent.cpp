// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bStartWithTickEnabled = false;
	PrimaryComponentTick.bCanEverTick = false;
	MaxHealth = 5.f;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage);
	}
}

void UHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (CurrentHealth <= 0.0f)
	{
		return;
	}

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	float HealthPercent = CurrentHealth / MaxHealth;

	UE_LOG(LogTemp, Warning, TEXT("%s took %f damage. Current Health @ %f"), *GetNameSafe(DamagedActor), Damage, CurrentHealth);

	if (CurrentHealth > 0.f)
	{
		if (Damage > 0.f)
		{
			OnHurt.Broadcast(HealthPercent);
		}
		else 
		{
			OnHeal.Broadcast(HealthPercent);
		}
	}
	else
	{
		OnDeath.Broadcast(HealthPercent);

		if (AActor* Owner = GetOwner())
		{
			Owner->OnTakeAnyDamage.RemoveDynamic(this, &UHealthComponent::HandleDamage);
		}
	}
}