/********************************************************************************
** Form generated from reading UI file 'raise.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAISE_H
#define UI_RAISE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_raise
{
public:
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *raise)
    {
        if (raise->objectName().isEmpty())
            raise->setObjectName(QString::fromUtf8("raise"));
        raise->resize(400, 300);
        textEdit = new QTextEdit(raise);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(90, 130, 221, 85));
        pushButton = new QPushButton(raise);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 250, 83, 29));
        pushButton_2 = new QPushButton(raise);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 250, 83, 29));
        label = new QLabel(raise);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 50, 221, 41));

        retranslateUi(raise);

        QMetaObject::connectSlotsByName(raise);
    } // setupUi

    void retranslateUi(QDialog *raise)
    {
        raise->setWindowTitle(QCoreApplication::translate("raise", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("raise", "Nosta", nullptr));
        pushButton_2->setText(QCoreApplication::translate("raise", "Peruuta", nullptr));
        label->setText(QCoreApplication::translate("raise", "Kirjoita Nostettava summa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class raise: public Ui_raise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAISE_H
