// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Actors/Rifle.h"
#include "Actors/Projectile.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "Both/GameHUD.h"
#include "BasePlayer.generated.h"

UCLASS()
class A_RICARDORODZ_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABasePlayer();

	UFUNCTION()
		void WinGame();

	UFUNCTION()
		void UnbindAllEvents();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Components)
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Components)
		class USpringArmComponent* SpringArm;

	UPROPERTY(EditDefaultsOnly, Category = HUDClassRef)
		TSubclassOf<UGameHUD> HUDClass;

	UPROPERTY(EditDefaultsOnly, Category = HUDObjectRef)
		UGameHUD* HUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = InstaRef)
		APlayerController* PlayerController;

	void HandleDeath(float Percent) override;
	virtual bool CanPickupHealth() override;

	UFUNCTION()
		void DeathEndedHandler();

	UFUNCTION()
		void Reload();

private:
	UFUNCTION()
		void InputAxisMoveForward(float AxisValue);

	UFUNCTION()
		void InputAxisStrafe(float AxisValue);

	UFUNCTION()
		void Attack();

};
