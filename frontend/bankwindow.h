#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QDialog>

namespace Ui {
class BankWindow;
}

class BankWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BankWindow(QString cardnum,bool credit,QWidget *parent = nullptr);

    const QString &getWebToken() const;


    void setWebToken(const QByteArray &newWebToken);

    ~BankWindow();


private:
    Ui::BankWindow *ui;
    bool usingCredit;
    QString idaccount;
    QString cardnum;
    QByteArray webToken;
};

#endif // BANKWINDOW_H
