// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "AIC_Agent.generated.h"

/**
 *
 */
UCLASS()
class A_RICARDORODZ_API AAgentAIController : public AAIController
{
	GENERATED_BODY()

public:
    AAgentAIController();

    UFUNCTION()
        void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
        FName PlayerKey;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Default)
        UAIPerceptionComponent* AIPerceptionComponent;

  /*  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
        UAISenseConfig_Sight* AICSightconfig;*/

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
        UBehaviorTree* BTAsset;

    virtual void OnPossess(APawn* InPawn) override;
};
