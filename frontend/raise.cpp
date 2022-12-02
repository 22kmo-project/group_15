#include "raise.h"
#include "ui_raise.h"

raise::raise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::raise)
{
    ui->setupUi(this);
}

raise::~raise()
{
    delete ui;
}
