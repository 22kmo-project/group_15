#include "bankwindow.h"
#include "ui_bankwindow.h"

BankWindow::BankWindow(QString cardnum,bool credit, QByteArray webToken,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankWindow)
{
    ui->setupUi(this);
    this->setWebToken("Bearer "+ webToken);
    this->getAccount(cardnum);
    this->usingCredit= credit;

}

void BankWindow::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;

}

BankWindow::~BankWindow()
{
    delete ui;
}


void BankWindow::dataSlot(QNetworkReply *reply)
{

    //qDebug()<<reply->readAll();
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QVariant id;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        if(usingCredit == true){
            if(json_obj["credit"].toInt() < 0) {
                qDebug()<<json_obj;
                id=json_obj["idaccount"].toVariant();
                idaccount+=id.toString();
            }else {}
        }


        else if(usingCredit == false){
            if(json_obj["credit"].toInt() == 0){
                qDebug()<<json_obj;
                id=json_obj["idaccount"].toVariant();
                idaccount+=id.toString();}}
    }




    qDebug()<<idaccount;
    ui->labelInfo->setText(idaccount);

    reply->deleteLater();
    dataManager->deleteLater();
}
void BankWindow::getAccount(QString cardnum){
    qDebug()<<webToken;
    QString site_url=url::getBaseUrl()+"/account/account/"+cardnum;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    dataManager = new QNetworkAccessManager(this);

    connect(dataManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = dataManager->get(request);
}

bool BankWindow::getCredit(){
    return usingCredit;
}
