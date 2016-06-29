/********************************************************************************
** Form generated from reading UI file 'BuyShell.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYSHELL_H
#define UI_BUYSHELL_H

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

class Ui_BuyShell
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLineEdit *stock;
    QLineEdit *shell;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLineEdit *max;
    QLabel *label_4;

    void setupUi(QWidget *BuyShell)
    {
        if (BuyShell->objectName().isEmpty())
            BuyShell->setObjectName(QStringLiteral("BuyShell"));
        BuyShell->resize(880, 559);
        label = new QLabel(BuyShell);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 70, 121, 21));
        pushButton = new QPushButton(BuyShell);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 115, 32));
        stock = new QLineEdit(BuyShell);
        stock->setObjectName(QStringLiteral("stock"));
        stock->setGeometry(QRect(310, 220, 113, 21));
        shell = new QLineEdit(BuyShell);
        shell->setObjectName(QStringLiteral("shell"));
        shell->setGeometry(QRect(310, 260, 113, 21));
        label_2 = new QLabel(BuyShell);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 220, 71, 21));
        label_3 = new QLabel(BuyShell);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 260, 91, 21));
        pushButton_2 = new QPushButton(BuyShell);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 220, 115, 32));
        max = new QLineEdit(BuyShell);
        max->setObjectName(QStringLiteral("max"));
        max->setGeometry(QRect(310, 300, 113, 21));
        label_4 = new QLabel(BuyShell);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 300, 101, 21));

        retranslateUi(BuyShell);

        QMetaObject::connectSlotsByName(BuyShell);
    } // setupUi

    void retranslateUi(QWidget *BuyShell)
    {
        BuyShell->setWindowTitle(QApplication::translate("BuyShell", "Form", 0));
        label->setText(QApplication::translate("BuyShell", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Buy Shell</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("BuyShell", "Return", 0));
        label_2->setText(QApplication::translate("BuyShell", "Stock", 0));
        label_3->setText(QApplication::translate("BuyShell", "Shell Number", 0));
        pushButton_2->setText(QApplication::translate("BuyShell", "Buy", 0));
        label_4->setText(QApplication::translate("BuyShell", "Max Price Limit", 0));
    } // retranslateUi

};

namespace Ui {
    class BuyShell: public Ui_BuyShell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYSHELL_H
