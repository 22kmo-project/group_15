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
        void setTimer(int time);

private slots:
    void on_pushButton_clicked();
    void TimerSlot();

private:
    Ui::withdrawDialog *ui;
    void closeWindow();
    QTimer * closeTimer;
    int timertime;

};

#endif // WITHDRAWDIALOG_H
