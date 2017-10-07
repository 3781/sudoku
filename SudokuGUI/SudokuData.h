#pragma once

#include <iostream>
#include <sstream>

class SudokuData
{
public:

    SudokuData();
    ~SudokuData();

    // �������ά��
    static const int DIMEN = 9;
    static const int SQRT_DIMEN = 3;

    void setData(int row, int col, int val);
    int getData(int row, int col);
    std::string toString();

private:
    // ���������
    int mData[DIMEN][DIMEN];
};

