// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTaskNode_FindRandomLocation.h"
#include "DrawDebugHelpers.h"

UBTTaskNode_FindRandomLocation::UBTTaskNode_FindRandomLocation()
{
	NodeName = TEXT("Find Random Location");

	// Accepting only vectors
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(
		UBTTaskNode_FindRandomLocation, BlackboardKey
	));
}

EBTNodeResult::Type UBTTaskNode_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	FNavLocation Location {};

	AAIController* AIControllerOwner { OwnerComp.GetAIOwner() };
	if (!IsValid(AIControllerOwner))
	{
		return EBTNodeResult::Failed;
	}

	const APawn* AIPawn { AIControllerOwner->GetPawn() };
	if (!IsValid(AIPawn))
	{
		return EBTNodeResult::Failed;
	}

	const FVector Origin { AIPawn->GetActorLocation() };

	// Setting navsystem and finding random location
	const UNavigationSystemV1* NavSystem{ UNavigationSystemV1::GetCurrent(GetWorld()) };
	if (IsValid(NavSystem) && NavSystem->GetRandomPointInNavigableRadius(Origin, SearchRadius, Location))
	{
		AIControllerOwner->GetBlackboardComponent()->SetValueAsVector(BlackboardKey.SelectedKeyName, Location.Location);

		DrawDebugSphere(GetWorld(), Location.Location, 5.f, 32, FColor::Red, false, 120);
	}

	// Finishing task and signaling that task completed successfuly
	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}

FString UBTTaskNode_FindRandomLocation::GetStaticDescription() const
{
	return FString::Printf(TEXT("Vector: %s"), *BlackboardKey.SelectedKeyName.ToString());
}
