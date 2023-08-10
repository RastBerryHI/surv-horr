// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAIController.h"
#include "BehaviorTree/BehaviorTree.h"

void AMyAIController::OnPossess(APawn* PawnPossessor)
{
	if (!IsValid(BehaviourTree))
	{
		UE_LOG(LogTemp, Error, TEXT("No BehaviourTree was set in %s"), *GetName());
		return;
	}

	RunBehaviorTree(BehaviourTree);
	Super::OnPossess(PawnPossessor);
}
