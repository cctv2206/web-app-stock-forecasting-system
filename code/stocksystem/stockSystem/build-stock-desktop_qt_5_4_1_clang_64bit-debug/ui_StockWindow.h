/********************************************************************************
** Form generated from reading UI file 'StockWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWindow
{
public:
    QLabel *label;
    QPushButton *ViewPortfo;
    QPushButton *ViewPrice;
    QPushButton *BuyShare;
    QPushButton *SellShare;
    QPushButton *Viewgraph;
    QPushButton *viewHist;
    QPushButton *pushButton_7;

    void setupUi(QWidget *StockWindow)
    {
        if (StockWindow->objectName().isEmpty())
            StockWindow->setObjectName(QStringLiteral("StockWindow"));
        StockWindow->resize(880, 559);
        label = new QLabel(StockWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 90, 200, 50));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        ViewPortfo = new QPushButton(StockWindow);
        ViewPortfo->setObjectName(QStringLiteral("ViewPortfo"));
        ViewPortfo->setGeometry(QRect(140, 200, 200, 40));
        ViewPrice = new QPushButton(StockWindow);
        ViewPrice->setObjectName(QStringLiteral("ViewPrice"));
        ViewPrice->setGeometry(QRect(450, 200, 200, 40));
        BuyShare = new QPushButton(StockWindow);
        BuyShare->setObjectName(QStringLiteral("BuyShare"));
        BuyShare->setGeometry(QRect(140, 260, 200, 40));
        SellShare = new QPushButton(StockWindow);
        SellShare->setObjectName(QStringLiteral("SellShare"));
        SellShare->setGeometry(QRect(450, 260, 200, 40));
        Viewgraph = new QPushButton(StockWindow);
        Viewgraph->setObjectName(QStringLiteral("Viewgraph"));
        Viewgraph->setGeometry(QRect(140, 320, 200, 40));
        viewHist = new QPushButton(StockWindow);
        viewHist->setObjectName(QStringLiteral("viewHist"));
        viewHist->setGeometry(QRect(450, 320, 200, 40));
        pushButton_7 = new QPushButton(StockWindow);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 20, 120, 30));
        QFont font1;
        font1.setPointSize(10);
        pushButton_7->setFont(font1);

        retranslateUi(StockWindow);
        QObject::connect(pushButton_7, SIGNAL(clicked()), StockWindow, SLOT(returnMain()));

        QMetaObject::connectSlotsByName(StockWindow);
    } // setupUi

    void retranslateUi(QWidget *StockWindow)
    {
        StockWindow->setWindowTitle(QApplication::translate("StockWindow", "Form", 0));
        label->setText(QApplication::translate("StockWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Stock Account System</span></p></body></html>", 0));
        ViewPortfo->setText(QApplication::translate("StockWindow", "View Portfolio", 0));
        ViewPrice->setText(QApplication::translate("StockWindow", "View Stock Price", 0));
        BuyShare->setText(QApplication::translate("StockWindow", "Buy Share", 0));
        SellShare->setText(QApplication::translate("StockWindow", "Sell Share", 0));
        Viewgraph->setText(QApplication::translate("StockWindow", "View Portfolio Graph", 0));
        viewHist->setText(QApplication::translate("StockWindow", "View Deal History", 0));
        pushButton_7->setText(QApplication::translate("StockWindow", "Return Main Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class StockWindow: public Ui_StockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
