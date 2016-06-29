#include "ViewPortf.h"
#include "ui_ViewPortf.h"

ViewPortf::ViewPortf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewPortf)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);

    StockAccount *bac = new StockAccount;// = new BankAccount;
    QString hist = QString::fromStdString(bac->showPortfolio());
    QLabel *his = new QLabel(hist);
    ui->s->setWidget(his);

}

ViewPortf::~ViewPortf()
{
    delete ui;
}

void ViewPortf::on_pushButton_clicked()
{
    StockWindow *sw = new StockWindow;
    this->close();
    this->~ViewPortf();
    sw->show();
}
