// Copyright Epic Games, Inc. All Rights Reserved.


#include "Actors/A_RicardoRodzGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

AA_RicardoRodzGameModeBase::AA_RicardoRodzGameModeBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AA_RicardoRodzGameModeBase::RemoveEnemy(AActor* DestroyedActor)
{
	NumberOfEnemies--;
	if (NumberOfEnemies <= 0)
	{
		if (ResultsWidget)
		{
			ResultsWidget->SetWin();
			ResultsWidget->AddToViewport();
		}
		if (CurrentPlayer)
		{
			CurrentPlayer->WinGame();
		}
	}
}

void AA_RicardoRodzGameModeBase::RemovePlayer(AActor* DestroyedActor)
{
	if (ResultsWidget)
	{
		ResultsWidget->AddToViewport();

		if (CurrentController)
		{
			CurrentController->bShowMouseCursor = true;

			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(ResultsWidget->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);

			CurrentController->SetInputMode(InputMode);

			TArray<AActor*> BasePlayers;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseCharacter::StaticClass(), BasePlayers);
			for (AActor* Actor : BasePlayers)
			{
				ABasePlayer* BasePlayer = Cast<ABasePlayer>(Actor);
				if (BasePlayer)
				{
					BasePlayer->OnDestroyed.RemoveDynamic(this, &AA_RicardoRodzGameModeBase::RemoveEnemy);
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("CurrentController is null in RemovePlayer"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ResultsWidget is null in RemovePlayer"));
	}
}

void AA_RicardoRodzGameModeBase::AddEnemy(AActor* Enemy)
{
	Enemy->OnDestroyed.AddDynamic(this, &AA_RicardoRodzGameModeBase::RemoveEnemy);

	NumberOfEnemies++;
}

void AA_RicardoRodzGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> BaseCharacters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseCharacter::StaticClass(), BaseCharacters);

	for (AActor* Actor : BaseCharacters)
	{
		ABasePlayer* Player = Cast<ABasePlayer>(Actor);
		if (Player)
		{
			Player->OnDestroyed.AddDynamic(this, &AA_RicardoRodzGameModeBase::RemovePlayer);
			CurrentPlayer = Player;
		}
		else
		{
			AddEnemy(Actor);
		}
	}

	CurrentController = Cast<APlayerController>(UGameplayStatics::GetActorOfClass(GetWorld(), PlayerControllerClass));

	if (ResultWidgetClass && CurrentController)
	{
		ResultsWidget = CreateWidget<UGameResults>(GetWorld(), ResultWidgetClass);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ResultWidgetClass is null."));
	}
}