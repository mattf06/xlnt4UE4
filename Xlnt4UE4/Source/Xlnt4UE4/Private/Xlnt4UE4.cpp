// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Xlnt4UE4.h"

DEFINE_LOG_CATEGORY(LogXlNT4UE4);

#define LOCTEXT_NAMESPACE "FXlnt4UE4Module"

void FXlnt4UE4Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FXlnt4UE4Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FXlnt4UE4Module, Xlnt4UE4)