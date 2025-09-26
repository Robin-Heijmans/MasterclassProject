using UnrealBuildTool;

public class MasterclassProjectCore : ModuleRules
{
    public MasterclassProjectCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "EnhancedInput", "InputCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "TowerDefenseCamera" });
    }
}