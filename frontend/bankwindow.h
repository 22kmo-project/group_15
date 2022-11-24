#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


#include "url.h"

namespace Ui {
class BankWindow;
}

class BankWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankWindow(QString cardnum,bool credit,QByteArray webToken, QWidget *parent = nullptr);

    const QByteArray &getWebToken() const;


    void setWebToken(const QByteArray &newWebToken);



    ~BankWindow();

private slots:

    void dataSlot (QNetworkReply *reply);

    void on_exitBtn_clicked();

private:
    Ui::BankWindow *ui;
    bool usingCredit;
    QString idaccount;
    QString cardnum;

    QByteArray webToken;
    QNetworkAccessManager *dataManager;
    void getAccount(QString cardnum);
    bool getCredit();
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // BANKWINDOW_H
