// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Variant.h"
#include "UObject/NoExportTypes.h"
#include "Xlnt4UE4.h"
#include <xlnt/xlnt.hpp>

#include "Cell.generated.h"

UENUM(BlueprintType)
enum class EValueType : uint8 {
    /// no value
    VT_empty UMETA(DisplayName = "Empty"),
    /// value is TRUE or FALSE
    VT_boolean UMETA(DisplayName = "Boolean"),
    /// value is an ISO 8601 formatted date
    VT_date UMETA(DisplayName = "Date"),
    /// value is a known error code such as \#VALUE!
    VT_error UMETA(DisplayName = "Error"),
    /// value is a string stored in the cell
    VT_inline_string UMETA(DisplayName = "String"),
    /// value is a number
    VT_number UMETA(DisplayName = "Number"),
    /// value is a string shared with other cells to save space
    VT_shared_string UMETA(DisplayName = "String (shared)"),
    /// value is the string result of a formula
    VT_formula_string UMETA(DisplayName = "Formula")
};

class UWorksheet;

/**
 *
 */
UCLASS(BlueprintType, Blueprintable)
class XLNT4UE4_API UCell : public UObject {
    GENERATED_BODY()

private:
    FVariant value;
    int32 column;
    int32 row;
    TWeakObjectPtr<UWorksheet> sheet;

public:
    static UCell* CreateObject(UWorksheet* sheet, int32 col, int32 row);

	static UCell* CreateObject(UWorksheet* sheet, const FString& ref);

    virtual ~UCell();

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Xlnt4UE4|Cell")
    EValueType ValueType;

    UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Cell")
    FString ValueAsString(bool& valid);

    UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Cell")
    float ValueAsNumber(bool& valid);

    UFUNCTION(BlueprintCallable, Category = "Xlnt4UE4|Cell")
    FString GetFormula(bool& valid);

    // for C++ client (FVariant is not available in Blueprint)
    FVariant GetValue() const;
};
