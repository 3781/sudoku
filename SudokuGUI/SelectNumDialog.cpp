#include "SelectNumDialog.h"
#include "ui_SelectNumDialog.h"

SelectNumDialog::SelectNumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNumDialog)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    showButtons();
}

SelectNumDialog::~SelectNumDialog()
{
    delete ui;
}

void SelectNumDialog::showButtons()
{
    int i, j, x = 20, y = 20, w = 50, h = 50;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            QPushButton *button = new QPushButton(ui->numGrid);
            button->setText(QString::number(i * 3 + j + 1));
            button->setGeometry(x, y, w, h);
            button->setObjectName(button->text());
            connect(button, SIGNAL(clicked()), parent(), SLOT(onSelectNumButtonClicked()));

            x += w + 2;
        }
        y += h + 2;
        x = 20;
    }
}
