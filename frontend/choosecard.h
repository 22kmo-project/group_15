#ifndef CHOOSECARD_H
#define CHOOSECARD_H

#include <QDialog>
#include "bankwindow.h"


namespace Ui {
class choosecard;
}

class choosecard : public QDialog
{
    Q_OBJECT

public:
    explicit choosecard(QString cardnum,QWidget *parent = nullptr);
    ~choosecard();

    const QByteArray &getWebToken() const;


    void setWebToken(const QByteArray &newWebToken);


private slots:
    void on_creditBtn_clicked();

    void on_debitBtn_clicked();

private:
    Ui::choosecard *ui;
    BankWindow *objectBankWindow;
    QByteArray webToken;
    QString myCard;
};

#endif // CHOOSECARD_H
