#ifndef RAISE_H
#define RAISE_H

#include <QDialog>

namespace Ui {
class raise;
}

class raise : public QDialog
{
    Q_OBJECT

public:
    explicit raise(QWidget *parent = nullptr);
    ~raise();

private:
    Ui::raise *ui;
};

#endif // RAISE_H
