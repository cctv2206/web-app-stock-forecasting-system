#ifndef BANKWINDOW_H
#define BANKWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <mainwindow.h>
#include <QLabel>
#include <BankAccount.h>
#include <BankDeposit.h>
#include <BW_ViewBalance.h>
#include <BankWithdraw.h>
#include <BankHis.h>

namespace Ui{
    class BankWindow;

}

class BankWindow : public QMainWindow
{
    Q_OBJECT
public:
     explicit BankWindow(QWidget *parent = 0 );
    ~BankWindow();

private slots:
    void returnMain();
    void on_ViewBal_clicked();

    void on_deposit_clicked();

    void on_withdrawl_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::BankWindow *ui;
    QLabel *label;
};


#endif // BANKWINDOW_H

