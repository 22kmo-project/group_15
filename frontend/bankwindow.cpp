#include "bankwindow.h"
#include "ui_bankwindow.h"

BankWindow::BankWindow(QString cardnum,bool credit, QByteArray webToken, QString iduser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BankWindow)
{
    ui->setupUi(this);
     QWidget::showMaximized();
    this->setWebToken("Bearer "+ webToken);
    this->getAccount(cardnum);
     this->iduser = iduser;
     this->getUser();
    this->usingCredit= credit;
     this->setWindowTitle("Valikko");

     QPixmap bkgnd(":/graphics/graphics/graphics/pic.png"); //tässä luodaan taustagrafiikka
     bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
     QPalette palette;
     palette.setBrush(QPalette::Window, bkgnd);
     this->setPalette(palette);


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
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        if(usingCredit == true){
            if(json_obj["credit"].toInt() < 0) {
                qDebug()<<json_obj["idaccount"].toString();
                idaccount=json_obj["idaccount"].toString();
            }else {}
        }


        else if(usingCredit == false){
            if(json_obj["credit"].toInt() == 0){
                qDebug()<<json_obj["idaccount"].toString();
                idaccount=json_obj["idaccount"].toString();}}
    }




    qDebug()<<idaccount;


    reply->deleteLater();
    dataManager->deleteLater();
}
void BankWindow::getAccount(QString cardnum){
    qDebug()<<webToken;
    QString site_url=url::getBaseUrl()+"/account/account/"+cardnum;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    dataManager = new QNetworkAccessManager(this);

    connect(dataManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(dataSlot(QNetworkReply*)));

    reply = dataManager->get(request);
}

void BankWindow::userSlot(QNetworkReply *reply)
{

    response_data=reply->readAll();

    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();


    name = json_obj["fname"].toString() + " " + json_obj["lname"].toString();

    ui->labelInfo->setText("Tilinumero: "+idaccount+ " \t\t Asiakas: " +name);

    reply->deleteLater();
    dataManager->deleteLater();
}
void BankWindow::getUser(){
    qDebug()<<webToken;
    QString site_url=url::getBaseUrl()+"/user/"+iduser;
    qDebug()<<site_url;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    userManager = new QNetworkAccessManager(this);

    connect(userManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(userSlot(QNetworkReply*)));

    reply = userManager->get(request);
}

bool BankWindow::getCredit(){
    return usingCredit;
}





void BankWindow::on_Btn_nosta_clicked()
{
    this->killDialogs();
    objectWithdraw=new withdraw(idaccount, webToken);
    objectWithdraw->show();
    boolwithdraw=true;

}


void BankWindow::on_Btn_saldo_clicked()
{
    this->killDialogs();
    objectStatus=new status(idaccount, webToken);
    objectStatus->show();
    boolstatus=true;
}


void BankWindow::on_Btn_loki_clicked()
{
    this->killDialogs();
    objectHistory=new history(idaccount, webToken);
    objectHistory->show();
    boolhistory=true;
    QObject::connect(objectHistory,&history::loggedout,this,&BankWindow::onLogout);
}

void BankWindow::on_Btn_lah_clicked()
{
    this->killDialogs();

    objectMoneysend=new moneysend(idaccount, webToken);
    objectMoneysend->show();
    boolmoneysend=true;

}

void BankWindow::on_Btn_exit_clicked()
{
    this->logOut();

}
void BankWindow::logOut(){
    this->killDialogs();
    emit loggedout();
    this->close();
}
void BankWindow::killDialogs(){
    if(boolhistory){
    delete objectHistory;
    objectHistory=nullptr;
    boolhistory=false;
    }
    if(boolstatus){
    delete objectStatus;
    objectStatus=nullptr;
    boolstatus=false;}
    if(boolwithdraw){
    delete objectWithdraw;
    objectWithdraw=nullptr;
    boolwithdraw=false;}
    if(boolmoneysend){
    delete objectMoneysend;
    objectMoneysend=nullptr;
    boolmoneysend=false;}
}

void BankWindow::onLogout()
{
   this->logOut();
}
