#include "BW_ViewBalance.h"
#include "ui_BW_ViewBalance.h"

BW_ViewBalance::BW_ViewBalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BW_ViewBalance)
{   BankAccount *bac = new BankAccount;// = new BankAccount;
    ui->setupUi(this);

    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);

    QString s = QString("$ %1").arg(bac->getBalance());
    QString sv = QString::number(bac->getBalance());
    QFont font = ui->money->font();
    font.setPointSize(26);
    font.setBold(true);
    ui->money->setFont(font);
    ui->money->setText(s);

    bac->~BankAccount();
}

BW_ViewBalance::~BW_ViewBalance()
{
    delete ui;
}

void BW_ViewBalance::on_pushButton_clicked()
{
    BankWindow *bw = new BankWindow;
    this->close();
    this->~BW_ViewBalance();
    bw->show();

}
