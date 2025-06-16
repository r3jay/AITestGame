// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/ButtonWText.h"

void UButtonWText::NativePreConstruct()
{
    Super::NativePreConstruct();

    if (Information)
    {
        Information->SetText(Info);  
    }
}

void UButtonWText::NativeConstruct()
{
    Super::NativeConstruct();

    if (ButtonBackground)
    {
        ButtonBackground->OnClicked.AddDynamic(this, &UButtonWText::HandleClick);
    }
}

void UButtonWText::HandleClick()
{
    OnButtonClick.Broadcast();
}