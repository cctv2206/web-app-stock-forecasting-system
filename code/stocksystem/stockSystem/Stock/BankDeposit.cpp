#include "BankDeposit.h"
#include "ui_BankDeposit.h"

BankDeposit::BankDeposit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BankDeposit)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

BankDeposit::~BankDeposit()
{
    delete ui;
}

void BankDeposit::on_deposit_clicked()
{
    double amount = ui->inputmoney->text().toDouble();
    BankAccount *bac = new BankAccount;
    bac->depositMoney(amount);
    QMessageBox *deposit = new QMessageBox;
    deposit->setText( "Successfully Deposit $ "+ ui->inputmoney->text());    //("Deposit", "Successfully Deposit $ "+ ui->inputmoney->text());
    deposit->show();
    bac->~BankAccount();
}

void BankDeposit::on_return_2_clicked()
{
    BankWindow *bw = new BankWindow;
    this->close();
    this->~BankDeposit();
    bw->show();

}
