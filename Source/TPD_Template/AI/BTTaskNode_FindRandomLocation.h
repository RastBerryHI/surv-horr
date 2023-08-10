// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTaskNode_FindRandomLocation.generated.h"

UCLASS()
class TPD_TEMPLATE_API UBTTaskNode_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTTaskNode_FindRandomLocation();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float SearchRadius{ 500.f };
};
