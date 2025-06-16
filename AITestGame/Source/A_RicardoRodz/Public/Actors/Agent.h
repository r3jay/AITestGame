// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/BaseCharacter.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/MeshComponent.h"
#include "Math/Color.h"
#include "EnemyInterface.h" 
#include "Agent.generated.h"


UCLASS()
class A_RICARDORODZ_API AAgent : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
public:

	AAgent();

	virtual void AgentAttack() override;
	virtual void AgentReload() override;

	UFUNCTION(BlueprintCallable)
		void EndAttack();

	UFUNCTION(BlueprintCallable)
		void UpdateHealth(float ratio);

	UFUNCTION(BlueprintCallable)
		void UpdateAmmo(float current, float max);

	UFUNCTION()
		void DeathEndedHandler();

protected:
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Color)
		FLinearColor ColorValue = FLinearColor(0.489583f, 0.0f, 0.0f, 1.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Name)
		FName ParameterName = FName("BodyColor");
};
