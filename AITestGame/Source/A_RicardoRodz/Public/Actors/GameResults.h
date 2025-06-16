// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/WidgetSwitcher.h"
#include "Both/ButtonWText.h"
#include "Actors/CoreGameInstance.h"
#include "GameResults.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API UGameResults : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UButtonWText* Exit;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UButtonWText* PlayAgain;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
        UCoreGameInstance* GameInstance;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UVerticalBox* ButtonArea;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UWidgetSwitcher* ResultsSwitch;

    UFUNCTION(BlueprintCallable)
        void SetWin();

    UFUNCTION(BlueprintCallable)
        void WinEnd();

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
        void HandleExitClicked();

    UFUNCTION()
        void HandlePlayAgainClicked();
};
