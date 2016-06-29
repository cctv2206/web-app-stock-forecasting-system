/********************************************************************************
** Form generated from reading UI file 'BW_ViewBalance.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BW_VIEWBALANCE_H
#define UI_BW_VIEWBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BW_ViewBalance
{
public:
    QLabel *label;
    QLabel *money;
    QPushButton *pushButton;

    void setupUi(QWidget *BW_ViewBalance)
    {
        if (BW_ViewBalance->objectName().isEmpty())
            BW_ViewBalance->setObjectName(QStringLiteral("BW_ViewBalance"));
        BW_ViewBalance->resize(880, 559);
        label = new QLabel(BW_ViewBalance);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 240, 181, 31));
        money = new QLabel(BW_ViewBalance);
        money->setObjectName(QStringLiteral("money"));
        money->setGeometry(QRect(390, 240, 191, 21));
        pushButton = new QPushButton(BW_ViewBalance);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 115, 32));

        retranslateUi(BW_ViewBalance);

        QMetaObject::connectSlotsByName(BW_ViewBalance);
    } // setupUi

    void retranslateUi(QWidget *BW_ViewBalance)
    {
        BW_ViewBalance->setWindowTitle(QApplication::translate("BW_ViewBalance", "Form", 0));
        label->setText(QApplication::translate("BW_ViewBalance", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Avaiable Balance</span></p></body></html>", 0));
        money->setText(QApplication::translate("BW_ViewBalance", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">TextLabel</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("BW_ViewBalance", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class BW_ViewBalance: public Ui_BW_ViewBalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BW_VIEWBALANCE_H
