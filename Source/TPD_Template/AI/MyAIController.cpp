// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

void AMyAIController::BeginPlay()
{
	if (!BehaviourTree) 
	{
		UE_LOG(LogTemp, Error, TEXT("No BehaviourTree was set in %s"), *GetName());
		return;
	}

	RunBehaviorTree(BehaviourTree);
}
