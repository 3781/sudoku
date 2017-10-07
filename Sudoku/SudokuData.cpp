#include "SudokuData.h"

SudokuData::SudokuData()
{
    memset(mData, 0, DIMEN * DIMEN * sizeof(int));
}


SudokuData::~SudokuData()
{
}

void SudokuData::setData(int row, int col, int val)
{
    if (row < 0 || row >= DIMEN) {
        return;
    }
    if (col < 0 || col >= DIMEN) {
        return;
    }

    mData[row][col] = val;
}

int SudokuData::getData(int row, int col)
{
    if (row < 0 || row >= DIMEN) {
        return 0;
    }
    if (col < 0 || col >= DIMEN) {
        return 0;
    }

    return mData[row][col];
}

std::string SudokuData::toString()
{
    int i, j;
    std::stringstream ss;

    for (i = 0; i < DIMEN; i++) {
        for (j = 0; j < DIMEN; j++) {
            ss << mData[i][j] << " ";
        }
        ss << std::endl;
    }

    return ss.str();
}

void SudokuData::reset()
{
    int i, j;
    for (i = 0; i < DIMEN; i++) {
        for (j = 0; j < DIMEN; j++) {
            mData[i][j] = 0;
        }
    }
}
