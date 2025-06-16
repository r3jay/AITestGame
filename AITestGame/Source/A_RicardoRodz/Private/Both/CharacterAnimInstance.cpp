// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/CharacterAnimInstance.h"


UCharacterAnimInstance::UCharacterAnimInstance()
{
	ActionSlot = FName("Action");
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);//Remember always Super:: if override

	APawn* Pawn = TryGetPawnOwner();
	if (nullptr != Pawn) 
	{
		//IsValid
		Speed = Pawn->GetVelocity().Size();
		Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
	}
	else 
	{
		//Is not Valid
		PreviewWindowUpdate();
	}
}

void UCharacterAnimInstance::PreviewWindowUpdate_Implementation()
{
	//Super::PreviewWindowUpdate_Implementation();

	if (bDebugAttack) 
	{
		AttackAnimation();
		bDebugAttack = false; 
	}
	if (bDebugHurt) 
	{
		HurtAnimation(0);
		bDebugHurt = false;
	}
	if (bDebugReload)
	{
		ReloadAnimation();
		bDebugReload = false;
	}
	else if(bDebugDead)
	{
		DeadAnimation(0);
		bDebugDead = false;
	}
}

void UCharacterAnimInstance::AttackAnimation_Implementation()
{
	if (AttackAsset)
	{
		UAnimMontage* Montage = PlaySlotAnimationAsDynamicMontage(AttackAsset, FName("Action"), 0.25f, 0.25f, 1.0f, 1, -1.0f, 0);

		if (!Montage)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to play slot animation as dynamic montage."));
		}
	}
}

void UCharacterAnimInstance::HurtAnimation_Implementation(float Percent)
{
	UAnimMontage* Montage = PlaySlotAnimationAsDynamicMontage(HurtAsset, FName("Action"), 0.25f, 0.25f, 1.0f, 1, -1.0f, 0);
}

void UCharacterAnimInstance::DeadAnimation_Implementation(float NotUsingYet)
{
	if (DeadAssets.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, DeadAssets.Num() - 1);
		DeadAsset = DeadAssets[Index];

		float AnimationLength = DeadAsset->GetPlayLength();

		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCharacterAnimInstance::DeathEnded, AnimationLength, false);
	}
}

void UCharacterAnimInstance::ReloadAnimation_Implementation()
{
	UAnimMontage* Montage = PlaySlotAnimationAsDynamicMontage(ReloadAsset, ActionSlot, 0.25f, 0.25f, 1.0f, 1, -1.0f, 0);
}

void UCharacterAnimInstance::DeathEnded()
{
	OnDeathEnded.Broadcast();
}