#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "history.h"
#include "status.h"
#include "withdraw.h"


#include "url.h"

namespace Ui {
class BankWindow;
}

class BankWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankWindow(QString cardnum,bool credit,QByteArray webToken,QString iduser,  QWidget *parent = nullptr);

    const QByteArray &getWebToken() const;


    void setWebToken(const QByteArray &newWebToken);



    ~BankWindow();

private slots:

    void dataSlot (QNetworkReply *reply);
    void userSlot (QNetworkReply *reply);


    void on_nostaBtn_clicked();

    void on_saldoBtn_clicked();

    void on_lokiBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::BankWindow *ui;
    bool usingCredit;
    QString idaccount;
    QString cardnum;
    QString name;
    QString iduser;

    withdraw *objectWithdraw;
    history *objectHistory;
    status *objectStatus;


    QByteArray webToken;
    QNetworkAccessManager *dataManager;
    QNetworkAccessManager *userManager;
    void getUser();
    void getAccount(QString cardnum);
    bool getCredit();
    QNetworkReply *reply;
    QByteArray response_data;
    bool boolhistory = 0, boolstatus = 0, boolwithdraw = 0;
    void logOut();
    void killDialogs();

signals:
    void loggedout();

};

#endif // BANKWINDOW_H
