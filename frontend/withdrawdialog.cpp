#include "withdrawdialog.h"
#include "ui_withdrawdialog.h"

withdrawDialog::withdrawDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::withdrawDialog)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);


    QPixmap bkgnd(":/graphics/graphics/graphics/pic.png"); //tässä luodaan taustagrafiikka
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    closeTimer = new QTimer(this);
    connect(closeTimer, &QTimer::timeout, this, QOverload<>::of(&withdrawDialog::TimerSlot));
    closeTimer->start(1000);
}

withdrawDialog::~withdrawDialog()
{
    delete ui;
}

void withdrawDialog::on_pushButton_clicked()
{
    this->closeWindow();
            emit resetTimer();
}

void withdrawDialog::TimerSlot()
{
    if(timertime > 0){
    this->ui->pushButton->setText(QString("Sulje (%1)").arg(timertime));
    timertime = timertime - 1;
    }
    else {
    closeTimer = nullptr;
    this->closeWindow();}
}

void withdrawDialog::closeWindow(){
    this->close();
            emit resetTimer();
}
void withdrawDialog::setText(QString text){
    this->ui->label->setText(text);
}
void withdrawDialog::setTimer(int time){
    timertime = time-1;
}

