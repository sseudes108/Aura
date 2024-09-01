

using UnrealBuildTool;
using System.Collections.Generic;

public class Aura_V2Target : TargetRules
{
	public Aura_V2Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "Aura_V2" } );
	}
}
