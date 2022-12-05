#include "moneysend.h"
#include "ui_moneysend.h"

moneysend::moneysend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moneysend)
{
    ui->setupUi(this);
}

moneysend::~moneysend()
{
    delete ui;
}
