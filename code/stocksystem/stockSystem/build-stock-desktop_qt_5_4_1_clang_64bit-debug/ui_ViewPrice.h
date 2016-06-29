/********************************************************************************
** Form generated from reading UI file 'ViewPrice.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWPRICE_H
#define UI_VIEWPRICE_H

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

class Ui_ViewPrice
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *input;
    QPushButton *view;
    QLabel *label_3;
    QLabel *price;
    QPushButton *pushButton;

    void setupUi(QWidget *ViewPrice)
    {
        if (ViewPrice->objectName().isEmpty())
            ViewPrice->setObjectName(QStringLiteral("ViewPrice"));
        ViewPrice->resize(880, 559);
        label = new QLabel(ViewPrice);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 80, 181, 41));
        label_2 = new QLabel(ViewPrice);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 220, 121, 21));
        input = new QLineEdit(ViewPrice);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(330, 220, 131, 21));
        view = new QPushButton(ViewPrice);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(520, 210, 115, 32));
        label_3 = new QLabel(ViewPrice);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 290, 59, 16));
        price = new QLabel(ViewPrice);
        price->setObjectName(QStringLiteral("price"));
        price->setGeometry(QRect(340, 290, 221, 20));
        pushButton = new QPushButton(ViewPrice);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 115, 32));

        retranslateUi(ViewPrice);

        QMetaObject::connectSlotsByName(ViewPrice);
    } // setupUi

    void retranslateUi(QWidget *ViewPrice)
    {
        ViewPrice->setWindowTitle(QApplication::translate("ViewPrice", "Form", 0));
        label->setText(QApplication::translate("ViewPrice", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">View Stock Price</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("ViewPrice", "<html><head/><body><p><span style=\" font-size:14pt;\">stock ticker</span></p></body></html>", 0));
        view->setText(QApplication::translate("ViewPrice", "View", 0));
        label_3->setText(QApplication::translate("ViewPrice", "<html><head/><body><p><span style=\" font-size:14pt;\">Price</span></p></body></html>", 0));
        price->setText(QApplication::translate("ViewPrice", "0", 0));
        pushButton->setText(QApplication::translate("ViewPrice", "Return", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewPrice: public Ui_ViewPrice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWPRICE_H
