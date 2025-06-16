// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Agent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Actors/HealthComponent.h"
#include "Materials/MaterialInterface.h"

AAgent::AAgent() : Super()
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void AAgent::BeginPlay()
{
    Super::BeginPlay();

    GetMesh()->SetVectorParameterValueOnMaterials(ParameterName, FVector(ColorValue.R, ColorValue.G, ColorValue.B));
    if (Weapon)
    {
        Weapon->OnActionStopped.AddDynamic(this, &AAgent::EndAttack);
    }
    if (HealthComponent)
    {
        HealthComponent->OnHurt.AddDynamic(this, &AAgent::UpdateHealth);
    }
    UpdateHealth(1);
    if (Weapon)
    {
        Weapon->OnAmmoChange.AddDynamic(this, &AAgent::UpdateAmmo);
        Weapon->ReloadAmmo();
    }
    if (CharacterAnimInstance) 
    {
        CharacterAnimInstance->OnDeathEnded.AddDynamic(this, &AAgent::DeathEndedHandler);
    }
}

void AAgent::AgentAttack()
{
    if (Weapon)
    {
        Weapon->Attack();
    }
}

void AAgent::AgentReload()
{
    if (Weapon)
    {
        Weapon->RequestReload();
    }
}

void AAgent::EndAttack()
{
    UAIBlueprintHelperLibrary::SendAIMessage(this, FName("ActionFinished"), nullptr, true);
}

void AAgent::UpdateHealth(float ratio)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController && AIController->GetBlackboardComponent())
    {
        AIController->GetBlackboardComponent()->SetValueAsFloat("HealthRatio", ratio);
    }
}

void AAgent::UpdateAmmo(float current, float max)
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController && AIController->GetBlackboardComponent())
    {
        AIController->GetBlackboardComponent()->SetValueAsFloat("Ammo", current);
    }
}

void AAgent::DeathEndedHandler()
{
    Destroy();
}

//void AAgent::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	if (Weapon)
//	{
//		Weapon->Attack();
//	}
//}