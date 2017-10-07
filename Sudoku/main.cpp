#include <iostream>
#include <fstream>

#include "SudokuGenerator.h"
#include "SudokuTest.h"

#define NUM_MAX 362880

int getVarNum(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "��������������������ȷ������sudoku.exe -c [n]   // --[n]������ĸ���" << std::endl;
        return 0;
    }

    if (strcmp(argv[1], "-c") != 0) {
        std::cout << "����1������������ȷ������sudoku.exe -c [n]   // --[n]������ĸ���" << std::endl;
        return 0;
    }

    int num;
    if ((sscanf_s(argv[2], "%d", &num)) != 1) {
        std::cout << "����2������������ȷ������sudoku.exe -c [n]   // --[n]������ĸ���" << std::endl;
        return 0;
    }

    if (num <= 0 || num > NUM_MAX) {
        std::cout << "����2������������ȷ��������ĸ�����1 <= n <= " << NUM_MAX << "��" << std::endl;
        return 0;
    }

    return num;
}

int main(int argc, char *argv[]) {

    int num = getVarNum(argc, argv);
    if (num == 0) {
        return -1;
    }

    SudokuGenerator generator;
    generator.setMatrixNum(num);

    std::ofstream outFile("sudoku.txt");

    if (!outFile) {
        std::cout << "����ļ�����ʧ��" << std::endl;
        return -1;
    }

    SudokuData data;
    while (generator.getNextMatrix(data)) {
        std::string str = data.toString();
        outFile << str << std::endl;

        if (!SudokuTest::validSudoku(data)) {
            std::cout << "������" << std::endl;
            break;
        }
    }

    outFile.close();

    return 0;
}