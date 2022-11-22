#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelInfo->hide();
    ui->labelInfo->setWordWrap(true);
    this->setWindowTitle("Kirjautuminen");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete objectBankWindow;
    objectBankWindow=nullptr;
    delete objectChooseCard;
    objectChooseCard=nullptr;
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

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString tokenstring;

    tokenstring = json_obj["token"].toString();
    QByteArray token = tokenstring.toUtf8();

    //mahdollista kortin valintaa varten rest api palauttaa json objektissa myös onko kortissa credit ominaisuus
    bool credit;
    if(json_obj["credit"].toInt() == 1){credit = true;}
    else{credit = false;}

    qDebug()<<token;
    qDebug()<<credit;


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
                if(credit == true){
                objectChooseCard=new choosecard(cardnum);
                objectChooseCard->setWebToken(token);
                objectChooseCard->show();
                }
                else{
                    objectBankWindow=new BankWindow(cardnum, false, token);
                    objectBankWindow->show();
                }


                ui->labelInfo->setText(QString("Toimii ja luottokortti: %1").arg(credit));

            }
        }
    }
    ui->labelInfo->show();
    reply->deleteLater();
    loginManager->deleteLater();

}

void MainWindow::on_cardpin_returnPressed()
{
    ui->btnLogin->click();
}

