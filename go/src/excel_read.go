package main

import (
    "fmt"
    "github.com/360EntSecGroup-Skylar/excelize"
)

func main() {
    xlsx, err := excelize.OpenFile("./book1.xlsx")
    if err != nil {
        fmt.Println(err)
        return
    }

    // Get value from cell by given worksheet name and axis
    cell := xlsx.GetCellValue("Sheet1", "B2")
    fmt.Println(cell)
    // fmt.Println("cell type = %T\n", type(cell))

    rows := xlsx.GetRows("Sheet1")
    for _, row := range rows {
        for _, colCell := range row {
            if colCell == "" {
                fmt.Print("dean ")
            } else {
                fmt.Print(colCell, "\t")
            }
        }
        fmt.Println()
    }

}