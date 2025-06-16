// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Projectile.h"
#include "Rifle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAmmoChange, float, CurrentAmmo, float, MaxAmmo);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponAction);

UCLASS()
class A_RICARDORODZ_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Attack();

	UFUNCTION(BlueprintCallable)
		void ActionStopped();

	UFUNCTION(BlueprintCallable)
		void OwnerDied();

	UFUNCTION(BlueprintPure) //Pure Function
		bool CanShoot() const;

	UPROPERTY(BlueprintAssignable, Category = Delegate) //Delegates
		FOnWeaponAction OnWeaponFired;

	UPROPERTY(BlueprintAssignable, Category = Delegates)
		FOnWeaponAction OnActionStopped;

	UPROPERTY(BlueprintAssignable, Category = Delegates)
		FOnWeaponAction OnReloadStart;

	UPROPERTY(BlueprintAssignable, Category = Delegates)
		FOnAmmoChange OnAmmoChange;

	UFUNCTION(BlueprintCallable)
		void ReloadAmmo();

	UFUNCTION(BlueprintCallable)
		void IncreaseMaxAmmo();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Ammo)
		float MaxAmmo;

	UFUNCTION(BlueprintCallable)
		void RequestReload();

	UFUNCTION(BlueprintCallable)
		void UseAmmo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
		class USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ClassRef)
		TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
		APawn* ParentPawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Name)
		FName SpawnSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Bool)
		bool bOnGoingAction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Bool)
		bool bOwnerAlive;

private:
	UPROPERTY(VisibleAnywhere, Category = Ammo)
		float CurrentAmmo;

	
};
