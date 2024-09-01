

using UnrealBuildTool;
using System.Collections.Generic;

public class Aura_V2EditorTarget : TargetRules
{
	public Aura_V2EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Aura_V2" } );
	}
}
