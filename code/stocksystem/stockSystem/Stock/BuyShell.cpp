#include "BuyShell.h"
#include "ui_BuyShell.h"

BuyShell::BuyShell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyShell)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

BuyShell::~BuyShell()
{
    delete ui;
}

void BuyShell::on_pushButton_clicked()
{
    StockWindow *bw = new StockWindow;
    this->close();
    this->~BuyShell();
    bw->show();
}

void BuyShell::on_pushButton_2_clicked()
{
    /*
     * double amount = ui->inputmoney->text().toDouble();
    BankAccount *bac = new BankAccount;
    bool ifwithdraw;
    ifwithdraw = bac->withdrawlMoney(amount);
    QMessageBox *deposit = new QMessageBox;
    if(ifwithdraw){
        deposit->setText( "Successfully Withdraw $ "+ ui->inputmoney->text());    //("Deposit", "Successfully Deposit $ "+ ui->inputmoney->text());

    }else{
        deposit->setText("Withdraw Fail!");
    }
    */
    StockAccount *sa = new StockAccount;
    double max = ui->max->text().toDouble();
    int shell =ui->shell->text().toInt();
    string stock = ui->stock->text().toStdString();
    int condition = sa->buyShares(shell, stock, max);
    QMessageBox *buy = new QMessageBox;
    if(condition == 0)
        buy->setText("Buy Fail! Not found stock" +  ui->stock->text());
    else if(condition ==1)
        buy->setText("Buy Fail! Price per share of stock " +  ui->stock->text() +" higher than max limit " + ui->max->text() );
    else if(condition ==2)
        buy->setText("Buy Fail! Insufficient balance in account !");
    else if(condition == 3)
        buy->setText("Buy Successfully Stock " + ui->stock->text() +"  "+ui->shell->text() +" shares in total $" + QString::number(shell*max)  );
    buy->show();
//    buy->~QMessageBox();
    sa->~StockAccount();
}
