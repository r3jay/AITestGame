// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Both/ButtonWText.h"
#include "Actors/CoreGameInstance.h"
#include "MainMenu.generated.h"

/**
 *
 */
UCLASS()
class A_RICARDORODZ_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UButtonWText* StartButton;

    UPROPERTY(BlueprintReadWrite, VisibleAnywhere, meta = (BindWidget))
        UButtonWText* QuitButton;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
        UCoreGameInstance* GameInstance;

protected:
	virtual void NativeConstruct() override;

    UFUNCTION()
        void HandleStartClicked();

    UFUNCTION()
        void HandleQuitClicked();
};
