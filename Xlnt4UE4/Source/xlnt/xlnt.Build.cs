// Some copyright should be here...

using UnrealBuildTool;
using System;
using System.IO;

public class xlnt : ModuleRules
{

    private string ThirdPartyPath
    {
        get
        {
            return Path.GetFullPath(Path.Combine(PluginDirectory, "ThirdParty/xlnt/installed"));
        }
    }

    public xlnt(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        Console.WriteLine("ThirdPartyPath: " + ThirdPartyPath);
        Console.WriteLine("PluginDirectory: " + PluginDirectory);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

            PrivateDefinitions.Add("XLNT_STATIC=1");
            PrivateDefinitions.Add("LIBSTUDXML_STATIC_LIB=1");
            PrivateDefinitions.Add("XML_STATIC=1");

            string LibDir = Path.Combine(ThirdPartyPath, "lib");
            bool bDebug = (Target.Configuration == UnrealTargetConfiguration.Debug && Target.bDebugBuildsActuallyUseDebugCRT);

            string[] libs;

            if (bDebug)
            {
                libs = new string[] { LibDir + "/xlntd.lib" };
            }
            else
            {
                libs = new string[] { LibDir + "/xlnt.lib" };
            }

            foreach (string lib in libs)
            {
                PublicAdditionalLibraries.Add(lib);
            }

            PublicIncludePaths.AddRange(
            new string[] {
                    // ... add public include paths required here ...
                    Path.Combine(ThirdPartyPath, "include"),
            }
            );


            PrivateIncludePaths.AddRange(
                new string[] {
				// ... add other private include paths required here ...
                Path.Combine(ThirdPartyPath, "include"),
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
}
