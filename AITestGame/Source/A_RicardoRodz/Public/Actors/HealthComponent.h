// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthComponent, float, HealthPercent);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), BlueprintType)
class A_RICARDORODZ_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnHealthComponent OnHurt;

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnHealthComponent OnDeath;

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnHealthComponent OnHeal;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxHealth)
		float MaxHealth;

private:
	float CurrentHealth;

	UFUNCTION()
		void HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
};
