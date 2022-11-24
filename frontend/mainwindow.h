#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QTimer>

#include "url.h"
#include "choosecard.h"
#include "bankwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString cardnum;
    choosecard *objectChooseCard;
    BankWindow *objectBankWindow;
    void reset();
    QTimer * ptimer;
    int timer = 20;

private slots:
    void on_btnLogin_clicked();
    void loginSlot (QNetworkReply *reply);
    void on_cardpin_returnPressed();
    void on_cardnum_returnPressed();
    void on_cardpin_textEdited(const QString &arg1);
    void TimerSlot();
};
#endif // MAINWINDOW_H
