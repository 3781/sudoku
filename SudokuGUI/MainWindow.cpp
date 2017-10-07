#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 固定窗口大小
    setFixedSize(width(),height());

    // 初始化数字选择对话框
    mSelectNumdialog = new SelectNumDialog(this);
    mSelectNumdialog->setModal(true);

    // 初始化数独网格
    initSudokuGrid();

    // 随机挖空
    randomEmpty();

    // 填充数据
    fillData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSudokuGrid()
{
    int i, j, x = 20, y = 20, w = 50, h = 50;

    for (i = 0; i < SudokuData::DIMEN; i++) {
        for (j = 0; j < SudokuData::DIMEN; j++) {
            QPushButton *button = new QPushButton(ui->sudokuGrid);
            button->setGeometry(x, y, w, h);
            mButtons[i][j] = button;

            x += w + 2;
        }
        y += h + 2;
        x = 20;
    }
}

void MainWindow::fillData()
{
    int i, j;

    for (i = 0; i < SudokuData::DIMEN; i++) {
        for (j = 0; j < SudokuData::DIMEN; j++) {
            QPushButton *button = mButtons[i][j];
            int value = mSudokuData.getData(i, j);
            if (value != 0) {
                button->setText(QString::number(value));
                button->setStyleSheet(QString::fromLocal8Bit("background-color:none;"));
                disconnect(button, &QPushButton::clicked, this, &MainWindow::onSudokuButtonClicked);
            } else {
                button->setText(QString::fromLocal8Bit(""));
                button->setStyleSheet(QString::fromLocal8Bit("background-color:white;"));
                connect(button, &QPushButton::clicked, this, &MainWindow::onSudokuButtonClicked);
            }
        }
    }

    mFilledNum = 0;
    ui->progressBar->setMaximum(mEmptyNum);
    ui->progressBar->setValue(mFilledNum);
}

void MainWindow::checkSudoku()
{
    bool isValid = SudokuTest::validSudoku(mSudokuData);
    if (isValid) {
        int ret = QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                           QString::fromLocal8Bit("Nice！这是一个正解！开始新游戏？"),
                                           QString::fromLocal8Bit("是"),
                                           QString::fromLocal8Bit("否"));
        if (ret == 0) {
            on_restartBtn_clicked();
        }
    } else {
        QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("这不是一个正解，请继续努力！"));
    }
}

void MainWindow::randomEmpty()
{
    int i, j;

    SudokuGenerator generator;
    generator.setMatrixNum(1);
    generator.getNextMatrix(mSudokuData);

    std::string str = mSudokuData.toString();
    std::ofstream outFile("C:/Users/ceshi/Desktop/answer.txt");
    if (!outFile) {
        std::cout << "打开文件失败" << std::endl;
    }
    outFile << str;
    outFile.close();

    srand(time(0));
    const int total = SudokuData::DIMEN * SudokuData::DIMEN;
    int a[total];
    for (i = 0; i < total; i++) {
        a[i] = i;
    }
    std::random_shuffle(a, a + total);

    mEmptyNum = rand() % 30 + 30;
    for (i = 0; i < mEmptyNum; i++) {
        int value = a[i];
        int row = value / SudokuData::DIMEN;
        int col = value % SudokuData::DIMEN;
        mSudokuData.setData(row, col, 0);
    }

    mOriginData = mSudokuData;
}

void MainWindow::on_restartBtn_clicked()
{
    randomEmpty();
    fillData();
}

void MainWindow::onSudokuButtonClicked()
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());
    int i, j;

    if (btn) {
        for (i = 0; i < SudokuData::DIMEN; i++) {
            for (j = 0; j < SudokuData::DIMEN; j++) {
                if (btn == mButtons[i][j]) {
                    mSelectNumdialog->show();
                    mCurRow = i;
                    mCurCol = j;
                    break;
                }
            }
        }
    }
}

void MainWindow::onSelectNumButtonClicked()
{
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());
    QString text = btn->text();
    mButtons[mCurRow][mCurCol]->setText(text);

    if (mSudokuData.getData(mCurRow, mCurCol) == 0) {
        mFilledNum++;
        ui->progressBar->setValue(mFilledNum);
    }

    mSudokuData.setData(mCurRow, mCurCol, text.toInt());
    mSelectNumdialog->hide();

    if (mFilledNum == mEmptyNum) {
        checkSudoku();
    }
}

void MainWindow::on_checkBtn_clicked()
{
    checkSudoku();
}

void MainWindow::on_clearBtn_clicked()
{
    mSudokuData = mOriginData;
    fillData();
}
