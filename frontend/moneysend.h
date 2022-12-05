#ifndef MONEYSEND_H
#define MONEYSEND_H

#include <QDialog>

namespace Ui {
class moneysend;
}

class moneysend : public QDialog
{
    Q_OBJECT

public:
    explicit moneysend(QWidget *parent = nullptr);
    ~moneysend();

private:
    Ui::moneysend *ui;
};

#endif // MONEYSEND_H
