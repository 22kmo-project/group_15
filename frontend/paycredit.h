#ifndef PAYCREDIT_H
#define PAYCREDIT_H

#include <QDialog>

namespace Ui {
class paycredit;
}

class paycredit : public QDialog
{
    Q_OBJECT

public:
    explicit paycredit(QWidget *parent = nullptr);
    ~paycredit();

private:
    Ui::paycredit *ui;
};

#endif // PAYCREDIT_H
