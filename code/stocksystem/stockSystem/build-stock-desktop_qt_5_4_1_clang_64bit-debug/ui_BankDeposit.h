/********************************************************************************
** Form generated from reading UI file 'BankDeposit.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKDEPOSIT_H
#define UI_BANKDEPOSIT_H

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

class Ui_BankDeposit
{
public:
    QLabel *label;
    QLineEdit *inputmoney;
    QLabel *label_2;
    QPushButton *deposit;
    QPushButton *return_2;

    void setupUi(QWidget *BankDeposit)
    {
        if (BankDeposit->objectName().isEmpty())
            BankDeposit->setObjectName(QStringLiteral("BankDeposit"));
        BankDeposit->resize(880, 559);
        label = new QLabel(BankDeposit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 90, 151, 41));
        inputmoney = new QLineEdit(BankDeposit);
        inputmoney->setObjectName(QStringLiteral("inputmoney"));
        inputmoney->setGeometry(QRect(330, 270, 113, 21));
        label_2 = new QLabel(BankDeposit);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 270, 111, 21));
        deposit = new QPushButton(BankDeposit);
        deposit->setObjectName(QStringLiteral("deposit"));
        deposit->setGeometry(QRect(520, 270, 115, 32));
        return_2 = new QPushButton(BankDeposit);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(20, 50, 115, 32));

        retranslateUi(BankDeposit);

        QMetaObject::connectSlotsByName(BankDeposit);
    } // setupUi

    void retranslateUi(QWidget *BankDeposit)
    {
        BankDeposit->setWindowTitle(QApplication::translate("BankDeposit", "Form", 0));
        label->setText(QApplication::translate("BankDeposit", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Deposit Money</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("BankDeposit", "deposit amount:", 0));
        deposit->setText(QApplication::translate("BankDeposit", "Deposit!", 0));
        return_2->setText(QApplication::translate("BankDeposit", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class BankDeposit: public Ui_BankDeposit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKDEPOSIT_H
