// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Rifle.h"
#include "Actors/Projectile.h"
#include "Both/CharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "HealthComponent.h"
#include "Actors/PickupInterface.h"
#include "BaseCharacter.generated.h"

UCLASS()
class A_RICARDORODZ_API ABaseCharacter : public ACharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual bool CanPickupHealth() override;

	UFUNCTION(BlueprintCallable)
		virtual void HandleDeath(float Percent);

	UFUNCTION(BlueprintCallable, Category = Getter)
		ARifle* GetWeapon() const { return Weapon; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
		UChildActorComponent* ChildActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ClassRef)
		TSubclassOf<ARifle> WeaponClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InstaRef)
		ARifle* Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
		UCharacterAnimInstance* CharacterAnimInstance;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Health)
		UHealthComponent* HealthComponent;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
