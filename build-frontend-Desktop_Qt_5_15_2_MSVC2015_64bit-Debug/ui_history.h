/********************************************************************************
** Form generated from reading UI file 'history.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORY_H
#define UI_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_history
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *history)
    {
        if (history->objectName().isEmpty())
            history->setObjectName(QString::fromUtf8("history"));
        history->resize(400, 300);
        scrollArea = new QScrollArea(history);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 100, 361, 151));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 359, 149));
        scrollArea->setWidget(scrollAreaWidgetContents);
        lineEdit = new QLineEdit(history);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 50, 361, 28));
        pushButton = new QPushButton(history);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 260, 83, 29));

        retranslateUi(history);

        QMetaObject::connectSlotsByName(history);
    } // setupUi

    void retranslateUi(QDialog *history)
    {
        history->setWindowTitle(QCoreApplication::translate("history", "Dialog", nullptr));
        lineEdit->setText(QCoreApplication::translate("history", "Viime aikaiset tapahtumat", nullptr));
        pushButton->setText(QCoreApplication::translate("history", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class history: public Ui_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORY_H
