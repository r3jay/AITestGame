// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AIC_Agent.h"

AAgentAIController::AAgentAIController()
{
    PrimaryActorTick.bCanEverTick = true;

    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
    //if (AIPerceptionComponent)
    //{
    //    AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AAgentAIController::OnTargetPerceptionUpdated);

    //    // Get the sense ID for the sight sense.
    //    FAISenseID SightSenseID = UAISense::GetSenseID(UAISense_Sight::StaticClass());

    //    // Now use the sense ID to get the sight config.
    //    UAISenseConfig_Sight* SightConfig = Cast<UAISenseConfig_Sight>(AIPerceptionComponent->GetSenseConfig(SightSenseID));
    //    if (SightConfig)
    //    {
    //        SightConfig->SightRadius = 900.0f;
    //        SightConfig->LoseSightRadius = 1100.0f;
    //        SightConfig->PeripheralVisionAngleDegrees = 40.0f;
    //        SightConfig->AutoSuccessRangeFromLastSeenLocation = 400.0f;
    //        SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    //        SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
    //        SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    //        // Update the perception component with the new sight config.
    //        AIPerceptionComponent->ConfigureSense(*SightConfig);
    //    }
    //}

    // Set up the PlayerKey for use with the blackboard
    PlayerKey = "Player";
}

void AAgentAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Blackboard)
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			Blackboard->SetValueAsObject(PlayerKey, Actor);
		}
		else
		{
			Blackboard->ClearValue(PlayerKey);
		}
	}
}

void AAgentAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (BTAsset)
	{
		RunBehaviorTree(BTAsset);
	}
}