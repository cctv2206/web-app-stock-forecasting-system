#include "BankWithdraw.h"
#include "ui_BankWithdraw.h"

BankWithdraw::BankWithdraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BankWithdraw)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

BankWithdraw::~BankWithdraw()
{
    delete ui;
}

void BankWithdraw::on_withdraw_clicked()
{
    double amount = ui->inputmoney->text().toDouble();
    BankAccount *bac = new BankAccount;
    bool ifwithdraw;
    ifwithdraw = bac->withdrawlMoney(amount);
    QMessageBox *deposit = new QMessageBox;
    if(ifwithdraw){
        deposit->setText( "Successfully Withdraw $ "+ ui->inputmoney->text());    //("Deposit", "Successfully Deposit $ "+ ui->inputmoney->text());

    }else{
        deposit->setText("Withdraw Fail!");
    }
    deposit->show();
    bac->~BankAccount();
}

void BankWithdraw::on_pushButton_2_clicked()
{
    BankWindow *bw = new BankWindow;
    this->close();
    this->~BankWithdraw();
    bw->show();
}
