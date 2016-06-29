/********************************************************************************
** Form generated from reading UI file 'bankaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKACCOUNT_H
#define UI_BANKACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *bankacc;
    QPushButton *ViewBal;
    QPushButton *deposit;
    QPushButton *withdrawl;
    QPushButton *pushButton_4;
    QPushButton *return_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(787, 423);
        bankacc = new QLabel(Form);
        bankacc->setObjectName(QStringLiteral("bankacc"));
        bankacc->setGeometry(QRect(270, 50, 191, 21));
        QFont font;
        font.setPointSize(18);
        bankacc->setFont(font);
        ViewBal = new QPushButton(Form);
        ViewBal->setObjectName(QStringLiteral("ViewBal"));
        ViewBal->setGeometry(QRect(270, 140, 200, 40));
        QFont font1;
        font1.setPointSize(14);
        ViewBal->setFont(font1);
        deposit = new QPushButton(Form);
        deposit->setObjectName(QStringLiteral("deposit"));
        deposit->setGeometry(QRect(270, 190, 200, 40));
        deposit->setFont(font1);
        withdrawl = new QPushButton(Form);
        withdrawl->setObjectName(QStringLiteral("withdrawl"));
        withdrawl->setGeometry(QRect(270, 240, 200, 40));
        withdrawl->setFont(font1);
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 290, 200, 40));
        pushButton_4->setFont(font1);
        return_2 = new QPushButton(Form);
        return_2->setObjectName(QStringLiteral("return_2"));
        return_2->setGeometry(QRect(270, 340, 200, 40));
        return_2->setFont(font1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        bankacc->setText(QApplication::translate("Form", "Bank Account System", 0));
        ViewBal->setText(QApplication::translate("Form", "View Avaiable Balance", 0));
        deposit->setText(QApplication::translate("Form", "Deposit Money", 0));
        withdrawl->setText(QApplication::translate("Form", "Withdrawal Money", 0));
        pushButton_4->setText(QApplication::translate("Form", "View History", 0));
        return_2->setText(QApplication::translate("Form", "Return Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKACCOUNT_H
