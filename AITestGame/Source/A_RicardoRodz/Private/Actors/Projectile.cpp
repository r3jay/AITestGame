// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Projectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
AProjectile::AProjectile()
{
	TimeToLive = 3.f;
	//Size = FVector(0.18f, 0.18f, 0.18f);
	Damage = 1.0f;

	PrimaryActorTick.bStartWithTickEnabled = false;

	SphereCollision = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SetRootComponent(SphereCollision);
	SphereCollision->SetWorldScale3D(FVector(0.18f, 0.18f, 0.18f));
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::HandleOverlap);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>("SphereMesh");
	SphereMesh->SetupAttachment(RootComponent);
	SphereMesh->SetRelativeScale3D(FVector(0.6f, 0.6f, 0.6f));
	SphereMesh->SetCollisionProfileName("NoCollision");


	if (ProjectileMeshAsset)
	{
		SphereMesh->SetStaticMesh(ProjectileMeshAsset);
	}

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->InitialSpeed = 1900.f;
	ProjectileMovement->MaxSpeed = 1900.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle ProjectileTimer;
	GetWorld()->GetTimerManager().SetTimer(ProjectileTimer, this, &AProjectile::K2_DestroyActor, TimeToLive);
	
	OwnerController = Cast<AController>(GetOwner());
	if (!OwnerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner not a controller"));
	}
	else 
	{
		UE_LOG(LogTemp, Log, TEXT("Owner is controller"));
	}
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		UGameplayStatics::ApplyDamage(OtherActor, Damage, OwnerController, this, NULL);

		Destroy();
	}
}

//void AProjectile::HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) 
//{
//	Destroy();
//}


//#include "UObject/ConstructorHelpers.h" //FOR POOR EXAMPLE

	//How to Bind to a delegate (All below was in constructor)
	//SphereCollision->OnComponentHit.AddDynamic(this, &AProjectile::HandleHit);

	//DO NOT DO THIS BAD HABIT
	//POOR EXAMPLE
	//static ConstructorHelpers::FObjectFinder<UStaticMesh>Asset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	//SphereMesh->SetStaticMesh(Asset.Object);
	//END POOR EXAMPLE

	//SphereCollision->InitSphereRadius(0.18f);
	//SphereCollision->SetGenerateOverlapEvents(true);
	//SphereCollision->SetCollisionProfileName("Projectile");