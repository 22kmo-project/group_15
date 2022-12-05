#include "moneysend.h"
#include "ui_moneysend.h"

moneysend::moneysend(QString idaccount, QByteArray webToken,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moneysend)
{
    objectDialogWindow=new withdrawDialog();
        setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
        ui->setupUi(this);
        QRegExpValidator* rxv = new QRegExpValidator(QRegExp("\\d*"), this);
        this->ui->lineReceiver->setValidator(rxv);
        this->ui->lineAmount->setValidator(rxv);
        this->idaccount = idaccount;
        this->webToken = webToken;
}

moneysend::~moneysend()
{
    delete ui;
}



void moneysend::dataSlot(QNetworkReply *reply)
{

    qDebug()<<reply->readAll();
    response_data=reply->readAll();
    int test=QString::compare(response_data,"false");
    qDebug()<< test;
    if(test==0){
        siirto = "siirto onnistui";;
    }
    else {siirto = "siirto epäonnistui";}

    objectDialogWindow->setText(siirto);
    objectDialogWindow->setTimer(10);
    objectDialogWindow->show();
    this->close();

    reply->deleteLater();
    updateManager->deleteLater();
}

void moneysend::sendMoney() {
    QString receiver = ui->lineReceiver->text();
    QString amount = ui->lineAmount->text();

    QJsonObject jsonObj;
    jsonObj.insert("receiver", receiver);
    jsonObj.insert("amount", amount);

    QString site_url=url::getBaseUrl()+"/account/transfer/"+this->idaccount;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    QByteArray myToken=webToken;
    request.setRawHeader(QByteArray("Authorization"),(this->webToken));
    //WEBTOKEN LOPPU

    updateManager = new QNetworkAccessManager(this);
    connect(updateManager, SIGNAL(finished(QNetworkReply *)), this,
            SLOT(dataSlot(QNetworkReply *)));

    reply = updateManager->put(request, QJsonDocument(jsonObj).toJson());
}


void moneysend::on_BTN_close_clicked()
{
    this->close();
}


void moneysend::on_BTN_send_clicked()
{
this->sendMoney();
}

