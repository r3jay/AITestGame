// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class A_RICARDORODZ_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Default)
		class USphereComponent* SphereCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Default)
		class UStaticMeshComponent* SphereMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		float TimeToLive;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		FVector Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
		UStaticMesh* ProjectileMeshAsset;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InstaRef)
		AController* OwnerController;

	UPROPERTY(EditDefaultsOnly)
		float Damage;

private:
	UFUNCTION()
		void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};