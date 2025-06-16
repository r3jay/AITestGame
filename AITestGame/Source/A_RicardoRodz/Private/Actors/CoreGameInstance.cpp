// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/CoreGameInstance.h"
#include "Kismet/GameplayStatics.h"

UCoreGameInstance::UCoreGameInstance()
{
    GameLevels.Add(FName("CoreMainMenu")); 
    GameLevels.Add(FName("CoreTestingMap")); 

    FirstLevelIndex = 1;     
    MainMenuIndex = 0;   
    CurrentLevelIndex = 1;
}

void UCoreGameInstance::LoadFirstLevel()
{
    LoadLevelSafe(FirstLevelIndex);
}

void UCoreGameInstance::LoadMainMenu()
{
    LoadLevelSafe(MainMenuIndex);
}

void UCoreGameInstance::LoadCurrentLevel()
{
    LoadLevelSafe(CurrentLevelIndex);
}

void UCoreGameInstance::QuitGame()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UCoreGameInstance::LoadLevelSafe(int32 LevelIndex)
{
    if (GameLevels.IsValidIndex(LevelIndex))
    {
        UGameplayStatics::OpenLevel(this, GameLevels[LevelIndex]);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Tried to load level with bad index: %d"), LevelIndex);
    }
}