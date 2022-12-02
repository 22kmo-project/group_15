/********************************************************************************
** Form generated from reading UI file 'choosecard.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECARD_H
#define UI_CHOOSECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choosecard
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *creditBtn;
    QPushButton *debitBtn;
    QLabel *label;

    void setupUi(QDialog *choosecard)
    {
        if (choosecard->objectName().isEmpty())
            choosecard->setObjectName(QString::fromUtf8("choosecard"));
        choosecard->resize(400, 300);
        horizontalLayoutWidget = new QWidget(choosecard);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 110, 381, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        creditBtn = new QPushButton(horizontalLayoutWidget);
        creditBtn->setObjectName(QString::fromUtf8("creditBtn"));
        creditBtn->setMinimumSize(QSize(0, 80));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        creditBtn->setFont(font);
        creditBtn->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(creditBtn);

        debitBtn = new QPushButton(horizontalLayoutWidget);
        debitBtn->setObjectName(QString::fromUtf8("debitBtn"));
        debitBtn->setMinimumSize(QSize(0, 80));
        debitBtn->setMaximumSize(QSize(16777215, 48));
        debitBtn->setFont(font);
        debitBtn->setStyleSheet(QString::fromUtf8(""));
        debitBtn->setFlat(false);

        horizontalLayout->addWidget(debitBtn, 0, Qt::AlignVCenter);

        label = new QLabel(choosecard);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 381, 91));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(choosecard);

        QMetaObject::connectSlotsByName(choosecard);
    } // setupUi

    void retranslateUi(QDialog *choosecard)
    {
        choosecard->setWindowTitle(QCoreApplication::translate("choosecard", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        creditBtn->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        creditBtn->setText(QCoreApplication::translate("choosecard", "Credit", nullptr));
#if QT_CONFIG(tooltip)
        debitBtn->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        debitBtn->setText(QCoreApplication::translate("choosecard", "Debit", nullptr));
        label->setText(QCoreApplication::translate("choosecard", "Valitse Credit tai Debit kortti", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choosecard: public Ui_choosecard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECARD_H
