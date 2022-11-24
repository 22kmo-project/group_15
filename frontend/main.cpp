#include "mainwindow.h"

#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //stylesheet
    QFile styleSheetFile("./Incrypt.qss");
    styleSheetFile.open(QFile::ReadWrite);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);


    MainWindow w;
    w.show();
    return a.exec();
}
