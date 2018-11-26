// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogXlNT4UE4, Log, All);

DECLARE_STATS_GROUP(TEXT("Cell"), STATGROUP_XLNT4UE4, STATCAT_Advanced)
DECLARE_CYCLE_STAT(TEXT("Cell - Creation"), STAT_CellCreation, STATGROUP_XLNT4UE4)
DECLARE_CYCLE_STAT(TEXT("Cell - GetValueAsString"), STAT_CellValueAsString, STATGROUP_XLNT4UE4)
DECLARE_CYCLE_STAT(TEXT("Cell - GetValueAsNumber"), STAT_CellValueAsNumber, STATGROUP_XLNT4UE4)
DECLARE_CYCLE_STAT(TEXT("Open file"), STAT_OpenFile, STATGROUP_XLNT4UE4)

class FXlnt4UE4Module : public IModuleInterface {
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
