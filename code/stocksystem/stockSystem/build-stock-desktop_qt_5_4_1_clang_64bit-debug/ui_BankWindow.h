/********************************************************************************
** Form generated from reading UI file 'BankWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKWINDOW_H
#define UI_BANKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BankWindow
{
public:
    QLabel *bankacc;
    QPushButton *ViewBal;
    QPushButton *deposit;
    QPushButton *withdrawl;
    QPushButton *pushButton_4;
    QPushButton *return_2;

    void setupUi(QWidget *BankWindow)
    {
        if (BankWindow->objectName().isEmpty())
            BankWindow->setObjectName(QStringLiteral("BankWindow"));
        BankWindow->resize(880, 559);
        bankacc = new QLabel(BankWindow);
        bankacc->setObjectName(QStringLiteral("bankacc"));
        bankacc->setGeometry(QRect(320, 70, 200, 30));
        QFont font;
        font.setPointSize(18);
        bankacc->setFont(font);
        ViewBal = new QPushButton(BankWindow);
        ViewBal->setObjectName(QStringLiteral("ViewBal"));
        ViewBal->setGeometry(QRect(320, 150, 200, 40));
        QFont font1;
        font1.setPointSize(14);
        ViewBal->setFont(font1);
        deposit = new QPushButton(BankWindow);
        deposit->setObjectName(QStringLiteral("deposit"));
        deposit->setGeometry(QRect(320, 200, 200, 40));
        deposit->setFont(font1);
        withdrawl = new QPushButton(BankWindow);
        withdrawl->setObjectName(QStringLiteral("withdrawl"));
        withdrawl->setGeometry(QRect(320, 250, 200, 40));
        withdrawl->setFont(font1);
        pushButton_4 = new QPushButton(BankWindow);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 300, 200, 40));
        pushButton_4->setFont(font1);
        return_2 = new QPushButton(BankWindow);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(20, 20, 120, 30));
        QFont font2;
        font2.setPointSize(10);
        return_2->setFont(font2);

        retranslateUi(BankWindow);
        QObject::connect(return_2, SIGNAL(clicked()), BankWindow, SLOT(returnMain()));

        QMetaObject::connectSlotsByName(BankWindow);
    } // setupUi

    void retranslateUi(QWidget *BankWindow)
    {
        BankWindow->setWindowTitle(QApplication::translate("BankWindow", "Form", 0));
        bankacc->setText(QApplication::translate("BankWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Bank Account System</span></p></body></html>", 0));
        ViewBal->setText(QApplication::translate("BankWindow", "View Avaiable Balance", 0));
        deposit->setText(QApplication::translate("BankWindow", "Deposit Money", 0));
        withdrawl->setText(QApplication::translate("BankWindow", "Withdraw Money", 0));
        pushButton_4->setText(QApplication::translate("BankWindow", "View History", 0));
        return_2->setText(QApplication::translate("BankWindow", "Return Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class BankWindow: public Ui_BankWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKWINDOW_H
