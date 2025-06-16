// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/MenuPlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void AMenuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (WidgetClass)  
    {
        UUserWidget* MenuWidget = CreateWidget<UUserWidget>(this, WidgetClass);
        if (MenuWidget)
        {
            MenuWidget->AddToViewport();

            FInputModeUIOnly InputMode;
            InputMode.SetWidgetToFocus(MenuWidget->TakeWidget());
            InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
            SetInputMode(InputMode);

            bShowMouseCursor = true;
        }
    }
}