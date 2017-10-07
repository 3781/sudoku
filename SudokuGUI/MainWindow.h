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
    // 重新开始游戏按钮事件响应
    void on_restartBtn_clicked();
    // 数独网格按钮事件响应
    void onSudokuButtonClicked();
    // 数字选择对话框按钮事件响应
    void onSelectNumButtonClicked();
    // 检查按钮事件响应
    void on_checkBtn_clicked();
    // 清空按钮事件响应
    void on_clearBtn_clicked();

private:
    Ui::MainWindow *ui;

    // 数独网格按钮对象的指针数组
    QPushButton *mButtons[SudokuData::DIMEN][SudokuData::DIMEN];

    // 数独解数据，包含玩家填充数据
    SudokuData mSudokuData;
    // 数独解原始数据，不包含玩家填充数据，用于清空按钮的还原数独网格
    SudokuData mOriginData;

    // 挖空的按钮数量
    int mEmptyNum;
    // 已经填空的按钮数量
    int mFilledNum;

    // 数字选择对话框对象指针
    SelectNumDialog *mSelectNumdialog;

    // 当前点击弹出数字选择对话框的按钮的行
    int mCurRow;
    // 当前点击弹出数字选择对话框的按钮的列
    int mCurCol;

    // 初始化数独网格
    void initSudokuGrid();

    // 随机挖空
    void randomEmpty();

    // 填充数据
    void fillData();

    // 检查是否是一个正确的数独解
    void checkSudoku();

};

#endif // MAINWINDOW_H
