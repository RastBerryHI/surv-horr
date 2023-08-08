// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPD_TemplateGameMode.h"
#include "TPD_TemplateCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPD_TemplateGameMode::ATPD_TemplateGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
