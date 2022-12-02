/********************************************************************************
** Form generated from reading UI file 'bankwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKWINDOW_H
#define UI_BANKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BankWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *nostaBtn;
    QPushButton *saldoBtn;
    QPushButton *lokiBtn;
    QPushButton *exitBtn;
    QLabel *labelInfo;
    QLabel *labelText2;
    QLabel *labelText1;

    void setupUi(QDialog *BankWindow)
    {
        if (BankWindow->objectName().isEmpty())
            BankWindow->setObjectName(QString::fromUtf8("BankWindow"));
        BankWindow->resize(436, 327);
        gridLayout = new QGridLayout(BankWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nostaBtn = new QPushButton(BankWindow);
        nostaBtn->setObjectName(QString::fromUtf8("nostaBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nostaBtn->sizePolicy().hasHeightForWidth());
        nostaBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(nostaBtn, 2, 0, 1, 1);

        saldoBtn = new QPushButton(BankWindow);
        saldoBtn->setObjectName(QString::fromUtf8("saldoBtn"));
        sizePolicy.setHeightForWidth(saldoBtn->sizePolicy().hasHeightForWidth());
        saldoBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(saldoBtn, 2, 1, 1, 1);

        lokiBtn = new QPushButton(BankWindow);
        lokiBtn->setObjectName(QString::fromUtf8("lokiBtn"));
        sizePolicy.setHeightForWidth(lokiBtn->sizePolicy().hasHeightForWidth());
        lokiBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lokiBtn, 5, 0, 1, 1);

        exitBtn = new QPushButton(BankWindow);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        sizePolicy.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(exitBtn, 5, 1, 1, 1);

        labelInfo = new QLabel(BankWindow);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelInfo->sizePolicy().hasHeightForWidth());
        labelInfo->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        labelInfo->setFont(font);
        labelInfo->setScaledContents(true);
        labelInfo->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelInfo, 6, 0, 1, 2);

        labelText2 = new QLabel(BankWindow);
        labelText2->setObjectName(QString::fromUtf8("labelText2"));
        sizePolicy1.setHeightForWidth(labelText2->sizePolicy().hasHeightForWidth());
        labelText2->setSizePolicy(sizePolicy1);
        labelText2->setMinimumSize(QSize(414, 53));
        QFont font1;
        font1.setPointSize(22);
        labelText2->setFont(font1);
        labelText2->setScaledContents(true);
        labelText2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelText2, 1, 0, 1, 2);

        labelText1 = new QLabel(BankWindow);
        labelText1->setObjectName(QString::fromUtf8("labelText1"));
        sizePolicy1.setHeightForWidth(labelText1->sizePolicy().hasHeightForWidth());
        labelText1->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(30);
        labelText1->setFont(font2);
        labelText1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelText1, 0, 0, 1, 2);


        retranslateUi(BankWindow);

        QMetaObject::connectSlotsByName(BankWindow);
    } // setupUi

    void retranslateUi(QDialog *BankWindow)
    {
        BankWindow->setWindowTitle(QCoreApplication::translate("BankWindow", "Dialog", nullptr));
        nostaBtn->setText(QCoreApplication::translate("BankWindow", "Nosta", nullptr));
        saldoBtn->setText(QCoreApplication::translate("BankWindow", "Saldo", nullptr));
        lokiBtn->setText(QCoreApplication::translate("BankWindow", "Tapahtumat", nullptr));
        exitBtn->setText(QCoreApplication::translate("BankWindow", "Kirjaudu ulos", nullptr));
        labelInfo->setText(QCoreApplication::translate("BankWindow", "TextLabel", nullptr));
        labelText2->setText(QCoreApplication::translate("BankWindow", "Kiitos kun k\303\244yt\303\244t ViKaSaKu Automaattia", nullptr));
        labelText1->setText(QCoreApplication::translate("BankWindow", "Valitse Toiminto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BankWindow: public Ui_BankWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKWINDOW_H
