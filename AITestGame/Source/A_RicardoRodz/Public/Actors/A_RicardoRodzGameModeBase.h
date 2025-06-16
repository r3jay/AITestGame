// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/GameResults.h"
#include "Actors/BasePlayer.h"
#include "A_RicardoRodzGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class A_RICARDORODZ_API AA_RicardoRodzGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
    AA_RicardoRodzGameModeBase();

    UFUNCTION()
        void RemoveEnemy(AActor* DestroyedActor);

    UFUNCTION()
        void RemovePlayer(AActor* DestroyedActor);

    UFUNCTION()
        void AddEnemy(AActor* Enemy);

protected:

    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ClassRef)
        TSubclassOf<UUserWidget> ResultWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ClassRef)
        UGameResults* ResultsWidget;

    UPROPERTY(EditAnywhere, Category = Code)
        int32 NumberOfEnemies;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Code)
        ABasePlayer* CurrentPlayer;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Code)
        APlayerController* CurrentController;
};
