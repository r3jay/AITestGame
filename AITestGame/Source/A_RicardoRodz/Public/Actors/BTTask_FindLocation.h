// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_FindLocation.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class A_RICARDORODZ_API UBTTask_FindLocation : public UBTTaskNode
{
    GENERATED_BODY()

public:
    UBTTask_FindLocation(FObjectInitializer const& object_initializer);

    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
        FBlackboardKeySelector LocationKey;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
        float Radius;
};

