// Fill out your copyright notice in the Description page of Project Settings.


#include "Both/GameHUD.h"
#include "Components/ProgressBar.h"

//UGameHUD::UGameHUD() : Super()
//{
//
//}

void UGameHUD::SetHealth(float Percent)
{
    if (HealthBar)
    {
        HealthBar->SetPercent(Percent);
    }
}

void UGameHUD::SetAmmo(float AvailableAmmo, float MaximumAmmo)
{
    if (CurrentAmmo)
    {
        CurrentAmmo->SetText(FText::AsNumber(AvailableAmmo));
    }

    if (MaxAmmo)
    {
        MaxAmmo->SetText(FText::AsNumber(MaximumAmmo));
    }
}
