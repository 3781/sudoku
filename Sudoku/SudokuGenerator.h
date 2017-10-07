#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <ctime>

#include "SudokuData.h"

class SudokuGenerator
{
public:

    SudokuGenerator();
    ~SudokuGenerator();

    // 设置生成数独解数量
    void setMatrixNum(int num);
    // 获得下一个数独解
    bool getNextMatrix(SudokuData &data);

private:

    // 数独解第一个九宫格排列
    int mFirstMatrix[SudokuData::DIMEN];

    // 生成的第一个九宫格排列集合
    std::map<std::string, int> mGeneratedFirstMatrices;

    // 生成数独解计数
    int mCount;
    // 数独解数量
    int mMatrixNum;

    // 获得下一个第一个九宫格排列
    void randomFirstMatrix();
    // 根据第一个九宫格排列生成一个数独解
    void generate(SudokuData &data);
};

