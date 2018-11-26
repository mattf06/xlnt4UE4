// Fill out your copyright notice in the Description page of Project Settings.

#include "Workbook.h"

void UWorkbook::AttachWorkbook(const xlnt::workbook& _wb)
{
	this->wb = _wb;
}

UWorkbook::~UWorkbook()
{
	UE_LOG(LogXlNT4UE4, Log, TEXT("Destroy UWorkbook (%s)"), *GetTitle());
}

UWorksheet * UWorkbook::ActiveSheet()
{
	xlnt::worksheet active = wb.active_sheet();

	UWorksheet * uws = NewObject<UWorksheet>(this);
	check(uws != nullptr);
	uws->AttachWorksheet(active);

	return uws;
}

UWorksheet * UWorkbook::SheetByTitle(const FString& title)
{
	try
	{
		const std::string t = std::string(TCHAR_TO_UTF8(*title));
		xlnt::worksheet ws = wb.sheet_by_title(t);
		UWorksheet * uws = NewObject<UWorksheet>(this);
		check(uws != nullptr);
		uws->AttachWorksheet(ws);
		return uws;
	}
	catch (std::exception)
	{
		return nullptr;
	}
}

UWorksheet * UWorkbook::SheetByIndex(int index)
{
	try
	{
		xlnt::worksheet ws = wb.sheet_by_index(index);
		UWorksheet * uws = NewObject<UWorksheet>(this);
		check(uws != nullptr);
		uws->AttachWorksheet(ws);
		return uws;
	}
	catch (std::exception)
	{
		return nullptr;
	}
}

int UWorkbook::SheetCount() const
{
	return int(wb.sheet_count());
}

FString UWorkbook::GetTitle() const
{
	if (wb.has_title())
	{
		return FString(UTF8_TO_TCHAR(wb.title().c_str()));
	}
	else
		return FString();
}
