// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AnimNotify_ReloadNow.h"
#include "Both/CharacterAnimInstance.h"

void UAnimNotify_ReloadNow::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    Super::Notify(MeshComp, Animation);

    UCharacterAnimInstance* AnimInst = Cast<UCharacterAnimInstance>(MeshComp->GetAnimInstance());

    if (AnimInst)
    {
        AnimInst->OnReloadNow.Broadcast();
    }
}