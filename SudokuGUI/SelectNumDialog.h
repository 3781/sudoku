#ifndef SELECTNUMDIALOG_H
#define SELECTNUMDIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class SelectNumDialog;
}

class SelectNumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNumDialog(QWidget *parent = 0);
    ~SelectNumDialog();

private:
    Ui::SelectNumDialog *ui;
    void showButtons();
};

#endif // SELECTNUMDIALOG_H
