// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class TPD_TEMPLATE_API AMyAIController : public AAIController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBehaviorTree* BehaviourTree;

	virtual void OnPossess(APawn* PawnPossessor) override;
};
