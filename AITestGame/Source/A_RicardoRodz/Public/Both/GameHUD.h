// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameHUD.generated.h"

/**
 *
 */
UCLASS()
class A_RICARDORODZ_API UGameHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	/*UGameHUD();*/

	UFUNCTION(BlueprintCallable, Category = Setters)
		void SetHealth(float Percent);

	UFUNCTION(BlueprintCallable, Category = Setters)
		void SetAmmo(float AvailableAmmo, float MaximumAmmo);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* CurrentAmmo;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* MaxAmmo;
};
