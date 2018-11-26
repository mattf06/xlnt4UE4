// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Xlnt4UE4BPLibrary.h"
#include "Misc/Paths.h"
#include "Xlnt4UE4.h"

#include <xlnt/xlnt.hpp>

DEFINE_LOG_CATEGORY_STATIC(LogXlnt4UE4BP, Log, All);
#define LOCTEXT_NAMESPACE "Xlnt4UE4BP"

UXlnt4UE4BPLibrary::UXlnt4UE4BPLibrary(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UWorkbook* UXlnt4UE4BPLibrary::OpenXLS(FString filename, bool& loaded)
{
    SCOPE_CYCLE_COUNTER(STAT_OpenFile);

    loaded = false;

    if (FPaths::FileExists(*filename)) {

        const std::string f = std::string(TCHAR_TO_UTF8(*filename));
        const xlnt::path filepath(f);
        xlnt::workbook wb(filepath);

        UWorkbook* uwb = NewObject<UWorkbook>();
        uwb->AttachWorkbook(wb);
        loaded = true;
        return uwb;
    } else {
        UE_LOG(LogXlnt4UE4BP, Error, TEXT("File not found (%s)!"), *filename);
        loaded = false;
        return nullptr;
    }
}

#undef LOCTEXT_NAMESPACE