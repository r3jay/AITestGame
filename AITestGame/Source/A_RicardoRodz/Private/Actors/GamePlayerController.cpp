// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/GamePlayerController.h"

AGamePlayerController::AGamePlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetInputMode(FInputModeGameOnly());
}