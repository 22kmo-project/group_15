#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelInfo->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnLogin_clicked()
{
    cardnum=ui->cardnum->text();
    QString cardpin=ui->cardpin->text();

    QJsonObject jsonObj;
    jsonObj.insert("cardnum",cardnum);
    jsonObj.insert("cardpin",cardpin);

    QString site_url=url::getBaseUrl()+"/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());


}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    int test=QString::compare(response_data,"false");
    int test2=QString::compare(response_data,"locked");
    qDebug()<<test;

    if(response_data.length()==0){
        ui->labelInfo->setText("Palvelin ei vastaa");
    }
    else {
        if(QString::compare(response_data,"-4078")==0){
            ui->labelInfo->setText("Virhe tietokanta yhteydessä");
        }
        else {
            if(test==0){
               // ui->cardnum->clear();
                ui->cardpin->clear();
                ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
            }
            else if(test2==0)
            {ui->labelInfo->setText("Kortti on lukittu, liian monta yritystä");}
            else {
                ui->labelInfo->setText("Toimii");
            }
        }
    }
    ui->labelInfo->show();
    reply->deleteLater();
    loginManager->deleteLater();

}
