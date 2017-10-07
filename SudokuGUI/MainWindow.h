#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <fstream>

#include "SudokuGenerator.h"
#include "SudokuTest.h"
#include "SelectNumDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // ���¿�ʼ��Ϸ��ť�¼���Ӧ
    void on_restartBtn_clicked();
    // ��������ť�¼���Ӧ
    void onSudokuButtonClicked();
    // ����ѡ��Ի���ť�¼���Ӧ
    void onSelectNumButtonClicked();
    // ��鰴ť�¼���Ӧ
    void on_checkBtn_clicked();
    // ��հ�ť�¼���Ӧ
    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;

    // ��������ť�����ָ������
    QPushButton *mButtons[SudokuData::DIMEN][SudokuData::DIMEN];

    // ���������ݣ���������������
    SudokuData mSudokuData;
    // ������ԭʼ���ݣ����������������ݣ�������հ�ť�Ļ�ԭ��������
    SudokuData mOriginData;

    // �ڿյİ�ť����
    int mEmptyNum;
    // �Ѿ���յİ�ť����
    int mFilledNum;

    // ����ѡ��Ի������ָ��
    SelectNumDialog *mSelectNumdialog;

    // ��ǰ�����������ѡ��Ի���İ�ť����
    int mCurRow;
    // ��ǰ�����������ѡ��Ի���İ�ť����
    int mCurCol;

    // ��ʼ����������
    void initSudokuGrid();

    // ����ڿ�
    void randomEmpty();

    // �������
    void fillData();

    // ����Ƿ���һ����ȷ��������
    void checkSudoku();

};

#endif // MAINWINDOW_H
