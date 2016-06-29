/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Stock;
    QPushButton *Bank;
    QPushButton *Exit;
    QLabel *AccountTitle;
    QMenuBar *menuBar;
    QMenu *menuWuyang;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(880, 559);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Stock = new QPushButton(centralWidget);
        Stock->setObjectName(QStringLiteral("Stock"));
        Stock->setGeometry(QRect(350, 180, 151, 41));
        QFont font;
        font.setPointSize(14);
        Stock->setFont(font);
        Bank = new QPushButton(centralWidget);
        Bank->setObjectName(QStringLiteral("Bank"));
        Bank->setGeometry(QRect(350, 240, 151, 41));
        Bank->setFont(font);
        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(350, 300, 151, 41));
        Exit->setFont(font);
        AccountTitle = new QLabel(centralWidget);
        AccountTitle->setObjectName(QStringLiteral("AccountTitle"));
        AccountTitle->setGeometry(QRect(310, 70, 281, 41));
        QFont font1;
        font1.setPointSize(18);
        AccountTitle->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 880, 22));
        menuWuyang = new QMenu(menuBar);
        menuWuyang->setObjectName(QStringLiteral("menuWuyang"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuWuyang->menuAction());

        retranslateUi(MainWindow);
        QObject::connect(Exit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        Stock->setText(QApplication::translate("MainWindow", "Stock Account", 0));
        Bank->setText(QApplication::translate("MainWindow", "Bank Account", 0));
        Exit->setText(QApplication::translate("MainWindow", "Exit Program", 0));
        AccountTitle->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Account Management System</span></p></body></html>", 0));
        menuWuyang->setTitle(QApplication::translate("MainWindow", "Wuyang", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
