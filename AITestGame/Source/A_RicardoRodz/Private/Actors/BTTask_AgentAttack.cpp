// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BTTask_AgentAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Actors/EnemyInterface.h"

UBTTask_AgentAttack::UBTTask_AgentAttack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//Here you can set up your node
}

EBTNodeResult::Type UBTTask_AgentAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    UE_LOG(LogTemp, Warning, TEXT("Agent Attack"));
    AAIController* const AIController = OwnerComp.GetAIOwner();    
    if (AIController)
    {
        IEnemyInterface* EnemyInterface = Cast<IEnemyInterface>(AIController->GetPawn());
        if (EnemyInterface)
        {
            EnemyInterface->AgentAttack();
            
            // Register to be notified when the "ActionFinished" message is broadcasted
            OwnerComp.RegisterMessageObserver(this, FName("ActionFinished"));
            return EBTNodeResult::InProgress;
        }
    }
    return EBTNodeResult::Failed;
}

void UBTTask_AgentAttack::OnMessage(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, FName Message, int32 RequestID, bool bSuccess)
{
	if (Message == FName("ActionFinished"))
	{
		FinishLatentTask(OwnerComp, bSuccess ? EBTNodeResult::Succeeded : EBTNodeResult::Failed);
	}
}