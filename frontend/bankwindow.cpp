#include "bankwindow.h"
#include "ui_bankwindow.h"

BankWindow::BankWindow(QString cardnum,bool credit,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankWindow)
{
    ui->setupUi(this);
}

void BankWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

BankWindow::~BankWindow()
{
    delete ui;
}
