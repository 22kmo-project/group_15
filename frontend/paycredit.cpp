#include "paycredit.h"
#include "ui_paycredit.h"

paycredit::paycredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paycredit)
{
    ui->setupUi(this);
}

paycredit::~paycredit()
{
    delete ui;
}
