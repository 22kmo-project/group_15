#ifndef MONEYSEND_H
#define MONEYSEND_H

#include <QDialog>

#include <QRegExpValidator>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "url.h"
#include "withdrawdialog.h"


namespace Ui {
class moneysend;
}

class moneysend : public QDialog
{
    Q_OBJECT

public:

    explicit moneysend(QString idaccount, QByteArray webToken,QWidget *parent = nullptr);
    ~moneysend();

private slots:
    void dataSlot (QNetworkReply *reply);

    void on_BTN_close_clicked();

    void on_BTN_send_clicked();

private:
    Ui::moneysend *ui;
    QString idaccount;
    QString siirto;

    QByteArray webToken;
    QNetworkAccessManager *updateManager;
    QNetworkReply *reply;
    QByteArray response_data;

    withdrawDialog *objectDialogWindow;

    void sendMoney();

};

#endif // MONEYSEND_H
