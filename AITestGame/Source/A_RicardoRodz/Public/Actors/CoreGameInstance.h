// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API UCoreGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
    UCoreGameInstance();

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        TArray<FName> GameLevels;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 FirstLevelIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 MainMenuIndex;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
        int32 CurrentLevelIndex;

    UFUNCTION(BlueprintCallable)
        void LoadFirstLevel();

    UFUNCTION(BlueprintCallable)
        void QuitGame();

    UFUNCTION(BlueprintCallable)
        void LoadLevelSafe(int32 LevelIndex);

    UFUNCTION(BlueprintCallable)
        void LoadMainMenu();

    UFUNCTION(BlueprintCallable)
        void LoadCurrentLevel();
	
};
