#ifndef WITHDRAWDIALOG_H
#define WITHDRAWDIALOG_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class withdrawDialog;
}

class withdrawDialog : public QWidget
{
    Q_OBJECT

public:
    explicit withdrawDialog(QWidget *parent = nullptr);
    ~withdrawDialog();

        void setText(QString text);
signals:
    void activity();

private slots:
    void on_pushButton_clicked();


private:
    Ui::withdrawDialog *ui;


signals:
    void loggedout();
        void resetTimer();

};

#endif // WITHDRAWDIALOG_H
