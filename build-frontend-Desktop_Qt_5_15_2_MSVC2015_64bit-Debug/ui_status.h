/********************************************************************************
** Form generated from reading UI file 'status.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUS_H
#define UI_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_status
{
public:
    QLabel *label;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QDialog *status)
    {
        if (status->objectName().isEmpty())
            status->setObjectName(QString::fromUtf8("status"));
        status->resize(400, 300);
        label = new QLabel(status);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 281, 20));
        graphicsView = new QGraphicsView(status);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(70, 50, 256, 192));
        pushButton = new QPushButton(status);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 260, 83, 29));

        retranslateUi(status);

        QMetaObject::connectSlotsByName(status);
    } // setupUi

    void retranslateUi(QDialog *status)
    {
        status->setWindowTitle(QCoreApplication::translate("status", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("status", "Tilisi tilanne juuri nyt", nullptr));
        pushButton->setText(QCoreApplication::translate("status", "Takaisin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class status: public Ui_status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUS_H
