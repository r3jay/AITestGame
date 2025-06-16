// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/GameResults.h"

void UGameResults::NativeConstruct()
{
    Super::NativeConstruct();

    if (UGameInstance* GI = GetWorld()->GetGameInstance())
    {
        GameInstance = Cast<UCoreGameInstance>(GI);
        if (!GameInstance)
        {
            UE_LOG(LogTemp, Warning, TEXT("You are looking for the code game instance"));
        }
    }
    if (Exit)
    {
        Exit->OnButtonClick.AddDynamic(this, &UGameResults::HandleExitClicked);
    }
    if (PlayAgain)
    {
        PlayAgain->OnButtonClick.AddDynamic(this, &UGameResults::HandlePlayAgainClicked);
    }
}

void UGameResults::SetWin()
{
    if (ButtonArea)
    {
        ButtonArea->SetVisibility(ESlateVisibility::Hidden); 
    }
    if (ResultsSwitch)
    {
        ResultsSwitch->SetActiveWidgetIndex(1); 
    }

    FTimerHandle TimerHandle;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UGameResults::WinEnd, 2.0f, false);
}


void UGameResults::WinEnd()
{
    if (GameInstance)
    {
        GameInstance->LoadMainMenu();  
    }
}

void UGameResults::HandleExitClicked()
{
    if (GameInstance)
    {
        GameInstance->LoadMainMenu();
    }
}

void UGameResults::HandlePlayAgainClicked()
{
    if (GameInstance)
    {
        GameInstance->LoadCurrentLevel();
    }
}