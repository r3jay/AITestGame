// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Rifle.h"
#include "Actors/Projectile.h"
#include "../../A_RicardoRodz.h"

// Sets default values
ARifle::ARifle()
{
	PrimaryActorTick.bStartWithTickEnabled = false;

	SpawnSocketName = FName("MuzzleFlashSocket");

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

	bOwnerAlive = true;

	MaxAmmo = 5;

	bOnGoingAction = false;
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();

	ParentPawn = Cast<APawn>(GetParentActor());
	if (ParentPawn)
	{
		UE_LOG(Game, Log, TEXT("Success!"));
		ReloadAmmo();
	}
	else
	{
		UE_LOG(Game, Error, TEXT("Parent Pawn is null!"));
		Destroy();
	}
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARifle::ActionStopped()
{
	bOnGoingAction = false;
	OnActionStopped.Broadcast();
}

void ARifle::OwnerDied()
{
	bOwnerAlive = false;
}

bool ARifle::CanShoot() const
{
	return !bOnGoingAction && bOwnerAlive && CurrentAmmo > 0;
}

void ARifle::Attack()
{
	if (CanShoot())  
	{
		FVector SocketLocation = SkeletalMesh->GetSocketLocation(SpawnSocketName);
		FRotator AimRotation = ParentPawn->GetBaseAimRotation();
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = ParentPawn->GetController();
		SpawnParams.Instigator = ParentPawn->GetInstigator();
		if (GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SocketLocation, AimRotation, SpawnParams))
		{
			bOnGoingAction = true;
			FTimerHandle ProjectileTimer;
			GetWorld()->GetTimerManager().SetTimer(ProjectileTimer, this, &ARifle::ActionStopped, 2);
			OnWeaponFired.Broadcast();
			UseAmmo();
		}
	}
}

void ARifle::ReloadAmmo()
{
	CurrentAmmo = MaxAmmo;
	OnAmmoChange.Broadcast(CurrentAmmo, MaxAmmo);
}

void ARifle::IncreaseMaxAmmo()
{
	MaxAmmo++;
	OnAmmoChange.Broadcast(CurrentAmmo, MaxAmmo);
}

void ARifle::RequestReload()
{
	if (!bOnGoingAction)
	{
		OnReloadStart.Broadcast();
		bOnGoingAction = true;
	}
}

void ARifle::UseAmmo()
{
	if (CurrentAmmo > 0)
	{
		--CurrentAmmo;
		OnAmmoChange.Broadcast(CurrentAmmo, MaxAmmo);
	}
}