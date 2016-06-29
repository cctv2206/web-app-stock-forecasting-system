#ifndef BANKDEPOSIT_H
#define BANKDEPOSIT_H

#include <QWidget>
#include <bankwindow.h>
#include<QMessageBox>
namespace Ui {
class BankDeposit;
}

class BankDeposit : public QWidget
{
    Q_OBJECT

public:
    explicit BankDeposit(QWidget *parent = 0);
    ~BankDeposit();

private slots:
    void on_deposit_clicked();

    void on_return_2_clicked();

private:
    Ui::BankDeposit *ui;
};

#endif // BANKDEPOSIT_H
