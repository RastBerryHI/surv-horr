// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPD_Template : ModuleRules
{
	public TPD_Template(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput"});

        PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "GameplayTasks", "NavigationSystem" });
	}
}
