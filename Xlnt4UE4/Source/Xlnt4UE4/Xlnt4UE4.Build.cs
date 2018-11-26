// Some copyright should be here...

using UnrealBuildTool;

public class Xlnt4UE4 : ModuleRules
{
    public Xlnt4UE4(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        bEnableExceptions = true;

        PrivateDefinitions.Add("XLNT_STATIC=1");
        PrivateDefinitions.Add("LIBSTUDXML_STATIC_LIB=1");
        PrivateDefinitions.Add("XML_STATIC=1");

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
            }
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
//                 "Slate",
//                 "SlateCore",
				// ... add private dependencies that you statically link with here ...	
                "xlnt"
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
