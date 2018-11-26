// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include <xlnt/xlnt.hpp>
#include "Xlnt4UE4.h"
#include "Worksheet.h"


#include "Workbook.generated.h"


/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class XLNT4UE4_API UWorkbook : public UObject
{
	GENERATED_BODY()

private:
	xlnt::workbook wb;

public:
	void AttachWorkbook(const xlnt::workbook& _wb);
	virtual ~UWorkbook();

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Workbook")
		UWorksheet * ActiveSheet();

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Workbook")
		UWorksheet * SheetByTitle(const FString& title);

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Workbook")
		UWorksheet * SheetByIndex(int index);

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Workbook")
		int SheetCount() const;

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Workbook")
		FString GetTitle() const;

};
