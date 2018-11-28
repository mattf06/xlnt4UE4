# xlnt for Unreal Engine 4 (xlnt4UE4)

A simple xlnt wrapper for UE4.

Provide Blueprint interface.

----------------------------------
The current version only support read operations and provides basic API to open xlsx file and read Workbook, Worksheet and Cell.

This is a very early version. It is focus on reading data, not about xls structure (style, properties, and so on)

This project use xlnt as sub-module. To compile xlnt4UE4 you have to build xlnt before and generate the "installed" folder.

**TODO:**
- finalize read access
- add write/create support
- direct import from xlsx to DataTable type
