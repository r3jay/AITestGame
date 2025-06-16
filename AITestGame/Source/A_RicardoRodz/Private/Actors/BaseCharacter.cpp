 // Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseCharacter.h"
#include "Both/CharacterAnimInstance.h"
#include "Blueprint/UserWidget.h"  

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));

    ChildActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActor"));
    ChildActor->SetupAttachment(GetMesh(), FName("PlaceWeaponHere"));

    HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

bool ABaseCharacter::CanPickupHealth()
{
    return false;
}

void ABaseCharacter::HandleDeath(float Percent)
{
    if (CharacterAnimInstance)
    {
        CharacterAnimInstance->DeadAnimation(Percent);
    }

    SetActorEnableCollision(false);

    if (Weapon)
    {
        Weapon->OwnerDied();
    }
}

void ABaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    ChildActor->SetChildActorClass(WeaponClass);
    AActor* SpawnedChildActor = ChildActor->GetChildActor();

    Weapon = Cast<ARifle>(SpawnedChildActor);
    if (Weapon)
    {
        UE_LOG(LogTemp, Warning, TEXT("Rifle equipped!"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Rifle not equipped!"));
        Destroy();
        return; 
    }

    CharacterAnimInstance = Cast<UCharacterAnimInstance>(GetMesh()->GetAnimInstance());
    if (CharacterAnimInstance)
    {
        Weapon->OnWeaponFired.AddDynamic(CharacterAnimInstance, &UCharacterAnimInstance::AttackAnimation);
        Weapon->OnReloadStart.AddDynamic(CharacterAnimInstance, &UCharacterAnimInstance::ReloadAnimation);

        CharacterAnimInstance->OnReloadEnd.AddDynamic(Weapon, &ARifle::ActionStopped);
        CharacterAnimInstance->OnReloadNow.AddDynamic(Weapon, &ARifle::ReloadAmmo);

        if (HealthComponent) 
        {
            HealthComponent->OnHurt.AddDynamic(CharacterAnimInstance, &UCharacterAnimInstance::HurtAnimation);
            HealthComponent->OnDeath.AddDynamic(this, &ABaseCharacter::HandleDeath);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to cast to character animation instance!"));
        Destroy();
    }
}
// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

