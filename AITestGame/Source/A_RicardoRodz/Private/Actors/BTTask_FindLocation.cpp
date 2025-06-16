// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BTTask_FindLocation.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindLocation::UBTTask_FindLocation(FObjectInitializer const& object_initializer)
    : Super(object_initializer)
{
    Radius = 1000.0f;
}

EBTNodeResult::Type UBTTask_FindLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);
    AAIController* const aiController = OwnerComp.GetAIOwner();
    APawn* const aiPawn = aiController ? aiController->GetPawn() : nullptr;
    if (aiPawn)
    {
        UNavigationSystemV1* const NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
        FNavLocation RandomPoint;
        if (NavSys && NavSys->GetRandomPointInNavigableRadius(aiPawn->GetActorLocation(), Radius, RandomPoint))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(LocationKey.SelectedKeyName, RandomPoint);
            return EBTNodeResult::Succeeded;
        }
    }
    return EBTNodeResult::Failed;
}
