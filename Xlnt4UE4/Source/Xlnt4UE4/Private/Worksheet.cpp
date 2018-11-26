// Fill out your copyright notice in the Description page of Project Settings.

#include "Worksheet.h"

void UWorksheet::AttachWorksheet(const xlnt::worksheet& worksheet)
{
	ws = worksheet;

	id = ws.id();
	title = FString(UTF8_TO_TCHAR(ws.title().c_str()));

}

UWorksheet::~UWorksheet()
{
	UE_LOG(LogXlNT4UE4, Log, TEXT("Destroy UWorksheet (%s)"), *title);
}

UCell * UWorksheet::GetCellAt(int32 column, int32 row)
{
	return UCell::CreateObject(this, column, row);
}

UCell * UWorksheet::GetCellByRef(const FString& ref)
{
	return UCell::CreateObject(this, ref);
}
