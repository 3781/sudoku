#include "SudokuGenerator.h"

SudokuGenerator::SudokuGenerator():
    mCount(0), mMatrixNum(0)
{
    int first = (7 + 4) % 9 + 1;
    mFirstMatrix[0] = first;
    for (int i = 1, t = 1; i <= SudokuData::DIMEN; i++) {
        if (i == first) {
            continue;
        }
        mFirstMatrix[t++] = i;
    }
}

SudokuGenerator::~SudokuGenerator()
{
}

void SudokuGenerator::setMatrixNum(int num)
{
    // ��յ�һ���Ź��񼯺�
    mGeneratedFirstMatrices.clear();

    mMatrixNum = num;
    mCount = 0;

    // �����������
    srand(time(0));
}

bool SudokuGenerator::getNextMatrix(SudokuData &data)
{
    if (mCount == mMatrixNum) {
        return false;
    }
    
    randomFirstMatrix();

    generate(data);

    mCount++;
    return true;
}

void SudokuGenerator::randomFirstMatrix()
{
    while (true) {
        // �����������
        std::random_shuffle(mFirstMatrix + 1, mFirstMatrix + SudokuData::DIMEN);

        std::stringstream ss;
        for (int i = 0; i < SudokuData::DIMEN; i++) {
            ss << mFirstMatrix[i];
        }
        std::string str = ss.str();

        // �����Ƿ��Ѿ����ڣ�������������ѭ��
        if (mGeneratedFirstMatrices.count(str) == 0) {
            mGeneratedFirstMatrices.insert(std::pair<std::string, int>(str, 1));
            break;
        }
    }
}

void SudokuGenerator::generate(SudokuData &data)
{
    int i, j, k;
    int sqrtDimen = SudokuData::SQRT_DIMEN;

    // �����һ���Ź�������
    for (i = 0, k = 0; i < SudokuData::SQRT_DIMEN; i++) {
        for (j = 0; j < SudokuData::SQRT_DIMEN; j++) {
            data.setData(i, j, mFirstMatrix[k++]);
        }
    }

    int firstRow, firstCol, t1, t2;

    // ������������������Ź�������
    for (t1 = 1; t1 < sqrtDimen; t1++) {
        firstRow = sqrtDimen * t1, firstCol = sqrtDimen * 0;
        for (j = firstCol; j < firstCol + sqrtDimen; j++) {
            int col = firstCol + (j + t1) % sqrtDimen;
            for (i = firstRow; i < firstRow + sqrtDimen; i++) {
                data.setData(i, j, data.getData(i % sqrtDimen, col));
            }
        }
    }

    // ����ʣ��Ź�������
    for (t1 = 0; t1 < sqrtDimen; t1++) {
        for (t2 = 1; t2 < sqrtDimen; t2++) {
            firstRow = sqrtDimen * t1, firstCol = sqrtDimen * t2;
            for (i = firstRow; i < firstRow + sqrtDimen; i++) {
                int row = firstRow + (i + t2) % sqrtDimen;
                for (j = firstCol; j < firstCol + sqrtDimen; j++) {
                    data.setData(i, j, data.getData(row, j % sqrtDimen));
                }
            }
        }
    }
}

