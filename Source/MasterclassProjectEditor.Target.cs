using UnrealBuildTool;

public class MasterclassProjectEditorTarget : TargetRules
{
    public MasterclassProjectEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        CppStandard = CppStandardVersion.Latest;
        ExtraModuleNames.AddRange( new string[] { "MasterclassProjectCore" } );
    }
}