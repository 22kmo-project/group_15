#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QDialog>

namespace Ui {
class BankWindow;
}

class BankWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankWindow(QWidget *parent = nullptr);
    ~BankWindow();

private:
    Ui::BankWindow *ui;
    bool usingCredit;
    QString idaccount;
    QString cardnum;
};

#endif // BANKWINDOW_H
