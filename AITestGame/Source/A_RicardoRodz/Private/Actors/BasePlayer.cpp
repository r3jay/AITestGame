// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ChildActorComponent.h"
#include "GameFramework/PlayerInput.h"


ABasePlayer::ABasePlayer() : Super()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0.f, 80.f, 90.f));
	SpringArm->TargetArmLength = 205.f;
	SpringArm->SetupAttachment(GetRootComponent()/*Socket Name*/);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetController());
	HUD = CreateWidget<UGameHUD>(PlayerController, HUDClass);
	if (HUD)
	{
		HUD->AddToViewport();
		if (HealthComponent)
		{
			HealthComponent->OnHeal.AddDynamic(HUD, &UGameHUD::SetHealth);
			HealthComponent->OnHurt.AddDynamic(HUD, &UGameHUD::SetHealth);
			HealthComponent->OnDeath.AddDynamic(HUD, &UGameHUD::SetHealth);
		}
		if(Weapon)
		{
			Weapon->OnAmmoChange.AddDynamic(HUD, &UGameHUD::SetAmmo);
			Weapon->ReloadAmmo();
		}
		if (CharacterAnimInstance) 
		{
			CharacterAnimInstance->OnDeathEnded.AddDynamic(this, &ABasePlayer::DeathEndedHandler);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("We need a player controller. (Or HUDWidget is null)"));
		Destroy();
	}
}

void ABasePlayer::DeathEndedHandler()
{
	Destroy();
}

void ABasePlayer::WinGame()
{
	if (HUD)
	{
		HUD->RemoveFromParent();
	}
	if (PlayerController)
	{
		DisableInput(PlayerController);
	}
	UnbindAllEvents(); 
}

void ABasePlayer::UnbindAllEvents()
{
	if (HealthComponent)
	{
		HealthComponent->OnHeal.Clear();
		HealthComponent->OnHurt.Clear();
		HealthComponent->OnDeath.Clear();
	}
	if (Weapon)
	{
		Weapon->OnAmmoChange.Clear();
	}
	if (CharacterAnimInstance)
	{
		CharacterAnimInstance->OnDeathEnded.Clear();
	}
}

void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Updated every frame, basically code for movement and animations, etc
}

void ABasePlayer::HandleDeath(float Percent)
{
	Super::HandleDeath(Percent);

	if (PlayerController) 
	{
		DisableInput(PlayerController);
	}
	if (HUD)
	{
		HUD->RemoveFromParent();
	}
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent); //If you want the same functionality of parent, use Super::

	//Turn
	PlayerInputComponent->BindAxis("TurnRight", this, &ABasePlayer::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABasePlayer::AddControllerPitchInput);

	//Move
	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::InputAxisMoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &ABasePlayer::InputAxisStrafe);

	//Attack
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("AttackInput"));
	PlayerInputComponent->BindAction("AttackInput", IE_Pressed, this, &ABasePlayer::Attack);

	//Reload
	UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("ReloadInput"));
	PlayerInputComponent->BindAction("ReloadInput", IE_Pressed, this, &ABasePlayer::Reload);
}

void ABasePlayer::InputAxisMoveForward(float AxisValue) //Created class for this purpose as Strafe
{
	//Step by step following Blueprints 
	//float Value = GetControlRotation().Yaw;
	//FVector Direction = FRotator(0.f, Value, 0.f).Vector();
	//AddMovementInput(Direction, AxisValue);
	// VERSUS following Blueprint but being more concise, avoiding creating temporary variables while having better memory management
	AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Vector(), AxisValue);
}

void ABasePlayer::InputAxisStrafe(float AxisValue)
{
	AddMovementInput(FRotator(0.f, GetControlRotation().Yaw, 0.f).Quaternion() * FVector::RightVector, AxisValue);
}

void ABasePlayer::Attack()
{
	if (Weapon)
	{
		Weapon->Attack();
		//if (CharacterAnimInstance)
		//{
			//CharacterAnimInstance->AttackAnimation();
		//}
	}
}
void ABasePlayer::Reload()
{
	if (Weapon)
	{
		Weapon->RequestReload();
	}
}

bool ABasePlayer::CanPickupHealth()
{
	return true;
}