#include "choosecard.h"
#include "ui_choosecard.h"

choosecard::choosecard(QString cardnum, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choosecard)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);

    ui->setupUi(this);
    this->setWindowTitle("Kortin valinta");
    myCard = cardnum;
}

choosecard::~choosecard()
{
    delete ui;
}

void choosecard::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
}

void choosecard::on_creditBtn_clicked()
{
    objectBankWindow=new BankWindow(myCard, true, webToken);
    objectBankWindow->show();

this->close();
}


void choosecard::on_debitBtn_clicked()
{    objectBankWindow=new BankWindow(myCard, false, webToken);
    objectBankWindow->show();
this->close();
}

