#include "sisaltoa.h"
#include "ui_sisaltoa.h"

Sisaltoa::Sisaltoa :
    QDialog(parent),
    ui(new Ui::Sisaltoa)
{
    ui->setupUi(this);
}

Sisaltoa::~Sisaltoa()
{
    delete ui;
}
