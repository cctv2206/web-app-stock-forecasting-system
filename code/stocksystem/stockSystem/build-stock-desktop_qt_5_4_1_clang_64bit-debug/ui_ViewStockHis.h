/********************************************************************************
** Form generated from reading UI file 'ViewStockHis.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSTOCKHIS_H
#define UI_VIEWSTOCKHIS_H

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

class Ui_ViewStockHis
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QScrollArea *s;
    QWidget *scrollAreaWidgetContents;
    QLabel *label2;

    void setupUi(QWidget *ViewStockHis)
    {
        if (ViewStockHis->objectName().isEmpty())
            ViewStockHis->setObjectName(QStringLiteral("ViewStockHis"));
        ViewStockHis->resize(880, 559);
        pushButton = new QPushButton(ViewStockHis);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 40, 115, 32));
        label = new QLabel(ViewStockHis);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 130, 231, 31));
        s = new QScrollArea(ViewStockHis);
        s->setObjectName(QStringLiteral("s"));
        s->setGeometry(QRect(170, 270, 481, 241));
        s->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 239));
        s->setWidget(scrollAreaWidgetContents);
        label2 = new QLabel(ViewStockHis);
        label2->setObjectName(QStringLiteral("label2"));
        label2->setGeometry(QRect(170, 240, 481, 20));

        retranslateUi(ViewStockHis);

        QMetaObject::connectSlotsByName(ViewStockHis);
    } // setupUi

    void retranslateUi(QWidget *ViewStockHis)
    {
        ViewStockHis->setWindowTitle(QApplication::translate("ViewStockHis", "Form", 0));
        pushButton->setText(QApplication::translate("ViewStockHis", "Return", 0));
        label->setText(QApplication::translate("ViewStockHis", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600;\">Stock Transcation History</span></p><p><span style=\" font-size:18pt; font-weight:600;\"><br/></span></p></body></html>", 0));
        label2->setText(QApplication::translate("ViewStockHis", "              Stock   Shares  PerShare$   Total$       Time", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewStockHis: public Ui_ViewStockHis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSTOCKHIS_H
