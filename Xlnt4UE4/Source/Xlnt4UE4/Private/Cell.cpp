// Fill out your copyright notice in the Description page of Project Settings.

#include "Cell.h"
#include "Worksheet.h"

UCell* UCell::CreateObject(UWorksheet* sheet, int32 col, int32 row)
{
    SCOPE_CYCLE_COUNTER(STAT_CellCreation);

    const xlnt::cell& c = sheet->ws.cell(xlnt::column_t(col), row);
    if (c.has_value()) {
        UCell* cell = NewObject<UCell>(sheet);

        cell->column = col;
        cell->row = row;
        cell->sheet = sheet;

        switch (c.data_type()) {
        case xlnt::cell_type::empty:
            cell->ValueType = EValueType::VT_empty;
            cell->value = FVariant();
            break;
        case xlnt::cell_type::boolean:
            cell->ValueType = EValueType::VT_boolean;
            cell->value = FVariant(c.value<bool>());
            break;
        case xlnt::cell_type::date:
            cell->ValueType = EValueType::VT_date;
            break;
        case xlnt::cell_type::error:
            cell->ValueType = EValueType::VT_error;
            cell->value = FVariant();
            break;
        case xlnt::cell_type::formula_string:
            cell->ValueType = EValueType::VT_formula_string;
            cell->value = FVariant(FString(c.formula().c_str()));
            break;
        case xlnt::cell_type::number:
            cell->ValueType = EValueType::VT_number;
            cell->value = FVariant(c.value<double>());
            break;
        case xlnt::cell_type::shared_string:
            cell->ValueType = EValueType::VT_shared_string;
            cell->value = FVariant(FString(c.to_string().c_str()));
            break;
        }

        return cell;
    }

    return nullptr;
}

UCell* UCell::CreateObject(UWorksheet* sheet, const FString& ref)
{
	SCOPE_CYCLE_COUNTER(STAT_CellCreation);

	const xlnt::cell& c = sheet->ws.cell(std::string(TCHAR_TO_UTF8(*ref)));
	return CreateObject(sheet, c.column().index, c.row());
}

UCell::~UCell()
{
    UE_LOG(LogXlNT4UE4, Log, TEXT("Destroy UCell (%d,%d)"), column, row);
}

FString UCell::ValueAsString(bool& valid)
{
    SCOPE_CYCLE_COUNTER(STAT_CellValueAsString);

    valid = false;

    if (sheet.IsValid()) {
        try {
            const xlnt::cell& c = sheet->ws.cell(xlnt::column_t(column), row);
            valid = true;
            return FString(c.to_string().c_str());
        } catch (std::exception& ex) {
            UE_LOG(LogXlNT4UE4, Error, TEXT("%s"), *FString(ex.what()));
            return FString();
        }
    } else {
        UE_LOG(LogXlNT4UE4, Error, TEXT("Invalid Sheet"));
        return FString();
    }
}

float UCell::ValueAsNumber(bool& valid)
{
    SCOPE_CYCLE_COUNTER(STAT_CellValueAsNumber);
    valid = false;

    if (sheet.IsValid()) {
        try {
            const xlnt::cell& c = sheet->ws.cell(xlnt::column_t(column), row);
            if (c.has_value() && c.data_type() == xlnt::cell::type::number) {
                valid = true;
                return c.value<float>();
            }
        } catch (std::exception& ex) {
            UE_LOG(LogXlNT4UE4, Error, TEXT("%s"), *FString(ex.what()));
            return 0.f;
        }
    } else {
        UE_LOG(LogXlNT4UE4, Error, TEXT("Invalid Sheet"));
    }
    return 0.f;
}

FString UCell::GetFormula(bool& valid)
{
    valid = false;

    if (sheet.IsValid()) {
        try {
            const xlnt::cell& c = sheet->ws.cell(xlnt::column_t(column), row);
            if (c.has_formula()) {
                valid = true;
                return FString(c.formula().c_str());
            }
        } catch (std::exception& ex) {
            UE_LOG(LogXlNT4UE4, Error, TEXT("%s"), *FString(ex.what()));
            return FString();
        }
    } else {
        UE_LOG(LogXlNT4UE4, Error, TEXT("Invalid Sheet"));
    }
    return FString();
}

FVariant UCell::GetValue() const
{
    return value;
}
