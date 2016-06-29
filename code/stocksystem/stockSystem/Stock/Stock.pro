#-------------------------------------------------
#
# Project created by QtCreator 2015-04-04T00:32:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    IOFile.cpp \
    Account.cpp \
    BankAccount.cpp \
    dLinkedList.cpp \
    StockAccount.cpp \
    stockNode.cpp \
    stockStruct.cpp \
    bankwindow.cpp \
    stockwindow.cpp \
    BW_ViewBalance.cpp \
    BankDeposit.cpp \
    BankWithdraw.cpp \
    BankHis.cpp \
    ViewPortf.cpp \
    ViewPrice.cpp \
    BuyShell.cpp \
    SellShare.cpp \
    ViewStockHis.cpp

HEADERS  += mainwindow.h \
    IOFile.h \
    Account.h \
    BankAccount.h \
    dLinkedList.h \
    StockAccount.h \
    stockNode.h \
    stockStruct.h \
    bankwindow.h \
    stockwindow.h \
    BW_ViewBalance.h \
    BankDeposit.h \
    BankWithdraw.h \
    BankHis.h \
    ViewPortf.h \
    ViewPrice.h \
    BuyShell.h \
    SellShare.h \
    ViewStockHis.h

FORMS    += mainwindow.ui \
    BankWindow.ui \
    StockWindow.ui \
    BW_ViewBalance.ui \
    BankDeposit.ui \
    BankWithdraw.ui \
    BankHis.ui \
    ViewPortf.ui \
    ViewPrice.ui \
    BuyShell.ui \
    SellShare.ui \
    ViewStockHis.ui

DISTFILES += \
    BW_ViewBalance.qml \
    BW_ViewBalance.ui.qml
