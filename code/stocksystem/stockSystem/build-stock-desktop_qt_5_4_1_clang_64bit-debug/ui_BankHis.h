/********************************************************************************
** Form generated from reading UI file 'BankHis.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BANKHIS_H
#define UI_BANKHIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BankHis
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QScrollArea *s;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *BankHis)
    {
        if (BankHis->objectName().isEmpty())
            BankHis->setObjectName(QStringLiteral("BankHis"));
        BankHis->resize(880, 559);
        pushButton = new QPushButton(BankHis);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 115, 32));
        label = new QLabel(BankHis);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 110, 231, 31));
        s = new QScrollArea(BankHis);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(220, 210, 391, 181));
        s->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 389, 179));
        s->setWidget(scrollAreaWidgetContents);

        retranslateUi(BankHis);

        QMetaObject::connectSlotsByName(BankHis);
    } // setupUi

    void retranslateUi(QWidget *BankHis)
    {
        BankHis->setWindowTitle(QApplication::translate("BankHis", "Form", 0));
        pushButton->setText(QApplication::translate("BankHis", "Return", 0));
        label->setText(QApplication::translate("BankHis", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Bank Transcation History</span></p><p><span style=\" font-size:18pt; font-weight:600;\"><br/></span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class BankHis: public Ui_BankHis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BANKHIS_H
