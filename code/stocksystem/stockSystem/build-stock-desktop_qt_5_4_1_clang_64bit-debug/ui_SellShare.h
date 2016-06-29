/********************************************************************************
** Form generated from reading UI file 'SellShare.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLSHARE_H
#define UI_SELLSHARE_H

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

class Ui_SellShare
{
public:
    QLabel *label;
    QLineEdit *min;
    QLineEdit *shell;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *Sell;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *stock;

    void setupUi(QWidget *SellShare)
    {
        if (SellShare->objectName().isEmpty())
            SellShare->setObjectName(QStringLiteral("SellShare"));
        SellShare->resize(880, 559);
        label = new QLabel(SellShare);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 80, 121, 21));
        min = new QLineEdit(SellShare);
        min->setObjectName(QStringLiteral("min"));
        min->setGeometry(QRect(370, 310, 113, 21));
        shell = new QLineEdit(SellShare);
        shell->setObjectName(QStringLiteral("shell"));
        shell->setGeometry(QRect(370, 270, 113, 21));
        label_4 = new QLabel(SellShare);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(190, 310, 101, 21));
        pushButton = new QPushButton(SellShare);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 115, 32));
        Sell = new QPushButton(SellShare);
        Sell->setObjectName(QStringLiteral("Sell"));
        Sell->setGeometry(QRect(550, 230, 115, 32));
        label_2 = new QLabel(SellShare);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 230, 71, 21));
        label_3 = new QLabel(SellShare);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 270, 91, 21));
        stock = new QLineEdit(SellShare);
        stock->setObjectName(QStringLiteral("stock"));
        stock->setGeometry(QRect(370, 230, 113, 21));

        retranslateUi(SellShare);

        QMetaObject::connectSlotsByName(SellShare);
    } // setupUi

    void retranslateUi(QWidget *SellShare)
    {
        SellShare->setWindowTitle(QApplication::translate("SellShare", "Form", 0));
        label->setText(QApplication::translate("SellShare", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Sell Share</span></p><p><br/></p></body></html>", 0));
        label_4->setText(QApplication::translate("SellShare", "Min Price Limit", 0));
        pushButton->setText(QApplication::translate("SellShare", "Return", 0));
        Sell->setText(QApplication::translate("SellShare", "Sell", 0));
        label_2->setText(QApplication::translate("SellShare", "Stock", 0));
        label_3->setText(QApplication::translate("SellShare", "Shell Number", 0));
    } // retranslateUi

};

namespace Ui {
    class SellShare: public Ui_SellShare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLSHARE_H
