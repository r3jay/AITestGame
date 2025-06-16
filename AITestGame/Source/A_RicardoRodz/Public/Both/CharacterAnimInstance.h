// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimSequenceBase.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAnimationEvent);

UCLASS()
class A_RICARDORODZ_API UCharacterAnimInstance : public UAnimInstance //Look for AnimInstance.h
{
	GENERATED_BODY()

public:
	UCharacterAnimInstance();

	void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnAnimationEvent OnReloadEnd;

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnAnimationEvent OnReloadNow;

	UPROPERTY(BlueprintAssignable, Category = Delegate)
		FOnAnimationEvent OnDeathEnded;

	UFUNCTION(BlueprintCallable)
		void DeathEnded();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		bool bDebugAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		bool bDebugHurt;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		bool bDebugDead;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		bool bDebugReload;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		float Speed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		float Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Default)
		FName ActionSlot;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void AttackAnimation();
	virtual void AttackAnimation_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void DeadAnimation(float NotUsingYet);
	virtual void DeadAnimation_Implementation(float NotUsingYet);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void HurtAnimation(float Percent);
	virtual void HurtAnimation_Implementation(float Percent);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void ReloadAnimation();
	virtual void ReloadAnimation_Implementation();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
		UAnimSequenceBase* AttackAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
		UAnimSequenceBase* HurtAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
		UAnimSequenceBase* DeadAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
		UAnimSequenceBase* ReloadAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
		TArray<UAnimSequenceBase*> DeadAssets;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void PreviewWindowUpdate();
	virtual void PreviewWindowUpdate_Implementation();

};
