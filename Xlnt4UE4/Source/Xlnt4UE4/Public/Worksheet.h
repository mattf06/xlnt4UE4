// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <xlnt/xlnt.hpp>
#include "Xlnt4UE4.h"
#include "Cell.h"


#include "Worksheet.generated.h"

/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class XLNT4UE4_API UWorksheet : public UObject
{
	GENERATED_BODY()

public:
	xlnt::worksheet ws;

public:
	void AttachWorksheet(const xlnt::worksheet& worksheet);

	virtual ~UWorksheet();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Xlnt4UE4|Worksheet")
		int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Xlnt4UE4|Worksheet")
		FString title;

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Worksheet")
		UCell * GetCellAt(int32 column, int32 row);

	UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Worksheet")
		UCell * GetCellByRef(const FString& ref);
};
