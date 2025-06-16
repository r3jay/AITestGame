// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/MainMenu.h"

void UMainMenu::NativeConstruct()
{
    Super::NativeConstruct();

    GameInstance = Cast<UCoreGameInstance>(GetGameInstance());
    if (!GameInstance)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to cast to UCoreGameInstance"));
    }

    if (StartButton)
    {
        StartButton->OnButtonClick.AddDynamic(GameInstance, &UCoreGameInstance::LoadFirstLevel);
    }

    if (QuitButton)
    {
        QuitButton->OnButtonClick.AddDynamic(GameInstance, &UCoreGameInstance::QuitGame);
    }
}

void UMainMenu::HandleStartClicked()
{
    if (GameInstance)
    {
        GameInstance->LoadFirstLevel();
    }
}

void UMainMenu::HandleQuitClicked()
{
    if (GameInstance)
    {
        GameInstance->QuitGame();
    }
}