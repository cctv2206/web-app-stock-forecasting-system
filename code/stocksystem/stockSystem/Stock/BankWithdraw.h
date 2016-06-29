#ifndef BANKWITHDRAW_H
#define BANKWITHDRAW_H

#include <QWidget>
#include <bankwindow.h>
#include<QMessageBox>
namespace Ui {
class BankWithdraw;
}

class BankWithdraw : public QWidget
{
    Q_OBJECT

public:
    explicit BankWithdraw(QWidget *parent = 0);
    ~BankWithdraw();

private slots:
    void on_withdraw_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BankWithdraw *ui;
};

#endif // BANKWITHDRAW_H
