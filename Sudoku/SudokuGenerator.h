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

    // ������������������
    void setMatrixNum(int num);
    // �����һ��������
    bool getNextMatrix(SudokuData &data);

private:

    // �������һ���Ź�������
    int mFirstMatrix[SudokuData::DIMEN];

    // ���ɵĵ�һ���Ź������м���
    std::map<std::string, int> mGeneratedFirstMatrices;

    // �������������
    int mCount;
    // ����������
    int mMatrixNum;

    // �����һ����һ���Ź�������
    void randomFirstMatrix();
    // ���ݵ�һ���Ź�����������һ��������
    void generate(SudokuData &data);
};

