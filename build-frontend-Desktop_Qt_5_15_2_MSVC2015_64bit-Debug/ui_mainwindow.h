/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnLogin;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *cardnum;
    QLineEdit *cardpin;
    QLabel *labelInfo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(380, 130, 91, 61));
        btnLogin->setAutoDefault(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 80, 91, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 140, 61, 41));
        label_2->setFont(font);
        cardnum = new QLineEdit(centralwidget);
        cardnum->setObjectName(QString::fromUtf8("cardnum"));
        cardnum->setGeometry(QRect(280, 81, 191, 31));
        cardnum->setFont(font);
        cardnum->setMaxLength(8);
        cardpin = new QLineEdit(centralwidget);
        cardpin->setObjectName(QString::fromUtf8("cardpin"));
        cardpin->setGeometry(QRect(280, 141, 81, 31));
        cardpin->setFont(font);
        cardpin->setMaxLength(4);
        cardpin->setEchoMode(QLineEdit::Password);
        labelInfo = new QLabel(centralwidget);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        labelInfo->setGeometry(QRect(180, 210, 291, 161));
        QFont font1;
        font1.setPointSize(16);
        labelInfo->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        btnLogin->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLogin->setText(QCoreApplication::translate("MainWindow", "Kirjaudu", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "KORTTI", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PIN ", nullptr));
        cardnum->setText(QString());
        cardpin->setInputMask(QString());
        cardpin->setText(QString());
        labelInfo->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortin numero ja paina Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
