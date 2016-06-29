#include "BankHis.h"
#include "ui_BankHis.h"

BankHis::BankHis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BankHis)
{
    ui->setupUi(this);

    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);

    BankAccount *bac = new BankAccount;// = new BankAccount;
    QString hist = QString::fromStdString(bac->printHistory());
    QLabel *his = new QLabel(hist);
    ui->s->setWidget(his);

    bac->~BankAccount();
}

BankHis::~BankHis()
{
    delete ui;
}


void BankHis::on_pushButton_clicked()
{
    BankWindow *bw = new BankWindow;
    this->close();
    this->~BankHis();
    bw->show();
}
