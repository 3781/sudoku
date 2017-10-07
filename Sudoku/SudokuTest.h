#pragma once

#include "SudokuData.h"

class SudokuTest
{
public:
    SudokuTest();
    ~SudokuTest();
    static bool validSudoku(SudokuData &data);
};

