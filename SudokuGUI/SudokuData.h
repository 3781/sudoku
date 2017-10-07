#pragma once

#include <iostream>
#include <sstream>

class SudokuData
{
public:

    SudokuData();
    ~SudokuData();

    // 数独解的维度
    static const int DIMEN = 9;
    static const int SQRT_DIMEN = 3;

    void setData(int row, int col, int val);
    int getData(int row, int col);
    std::string toString();

private:
    // 数独解矩阵
    int mData[DIMEN][DIMEN];
};

