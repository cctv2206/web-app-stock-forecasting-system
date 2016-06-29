/********************************************************************************
** Form generated from reading UI file 'BankWithdraw.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKWITHDRAW_H
#define UI_BANKWITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BankWithdraw
{
public:
    QPushButton *withdraw;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *inputmoney;
    QLabel *label_2;

    void setupUi(QWidget *BankWithdraw)
    {
        if (BankWithdraw->objectName().isEmpty())
            BankWithdraw->setObjectName(QStringLiteral("BankWithdraw"));
        BankWithdraw->resize(880, 559);
        withdraw = new QPushButton(BankWithdraw);
        withdraw->setObjectName(QStringLiteral("withdraw"));
        withdraw->setGeometry(QRect(540, 200, 115, 32));
        label = new QLabel(BankWithdraw);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 210, 111, 20));
        pushButton_2 = new QPushButton(BankWithdraw);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 20, 115, 32));
        inputmoney = new QLineEdit(BankWithdraw);
        inputmoney->setObjectName(QStringLiteral("inputmoney"));
        inputmoney->setGeometry(QRect(340, 210, 113, 21));
        label_2 = new QLabel(BankWithdraw);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 70, 151, 31));

        retranslateUi(BankWithdraw);

        QMetaObject::connectSlotsByName(BankWithdraw);
    } // setupUi

    void retranslateUi(QWidget *BankWithdraw)
    {
        BankWithdraw->setWindowTitle(QApplication::translate("BankWithdraw", "Form", 0));
        withdraw->setText(QApplication::translate("BankWithdraw", "withdraw", 0));
        label->setText(QApplication::translate("BankWithdraw", "Withdraw Amount", 0));
        pushButton_2->setText(QApplication::translate("BankWithdraw", "Return", 0));
        label_2->setText(QApplication::translate("BankWithdraw", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Withdraw Money</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class BankWithdraw: public Ui_BankWithdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKWITHDRAW_H
