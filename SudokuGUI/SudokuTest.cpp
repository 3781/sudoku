#include "SudokuTest.h"

SudokuTest::SudokuTest()
{
}


SudokuTest::~SudokuTest()
{
}

bool SudokuTest::validSudoku(SudokuData &data)
{
    int i, j, k, m, n;
    const int DIMEN = SudokuData::DIMEN;
    const int DIMEN_SMALL = SudokuData::SQRT_DIMEN;
    int mask[DIMEN + 1];

    for (i = 0; i < DIMEN; i++) {
        memset(mask, 0, sizeof(int) * (DIMEN + 1));
        for (j = 0; j < DIMEN; j++) {
            if (data.getData(i, j) < 1 || data.getData(i, j) > DIMEN) {
                //std::cout << "非法数字 " << a[i][j] << " 在第 " << (i + 1) << " 行" << std::endl;
                return false;
            }
            mask[data.getData(i, j)]++;
        }
        for (k = 1; k <= DIMEN; k++) {
            if (mask[k] != 1) {
                //std::cout << "第 " << (i + 1) << " 行不符合规则" << std::endl;
                return false;
            }
        }
    }

    for (j = 0; j < DIMEN; j++) {
        memset(mask, 0, sizeof(int) * (DIMEN + 1));
        for (i = 0; i < DIMEN; i++) {
            mask[data.getData(i, j)]++;
        }
        for (k = 1; k <= DIMEN; k++) {
            if (mask[k] != 1) {
                //std::cout << "第 " << (j + 1) << " 列不符合规则" << std::endl;
                return false;
            }
        }
    }

    for (i = 0; i < DIMEN; i += 3) {
        for (j = 0; j < DIMEN; j += 3) {

            memset(mask, 0, sizeof(int) * (DIMEN + 1));

            for (m = 0; m < DIMEN_SMALL; m++) {
                for (n = 0; n < DIMEN_SMALL; n++) {
                    mask[data.getData(i + m, j + n)]++;
                }
            }

            for (k = 1; k <= DIMEN; k++) {
                if (mask[k] != 1) {
                    //std::cout << "第 " << ((i / DIMEN) * DIMEN_SMALL + j + 1) << " 宫格不符合规则" << std::endl;
                    return false;
                }
            }

        }
    }

    //std::cout << "合法" << std::endl;
    return true;
}
