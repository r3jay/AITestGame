// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlueprintBase.h"
#include "Actors/EnemyInterface.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_AgentAttack.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class A_RICARDORODZ_API UBTTask_AgentAttack : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTask_AgentAttack(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnMessage(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, FName Message, int32 RequestID, bool bSuccess) override;
};

//Category = "Task", meta = (DisplayName = "AttackTask"