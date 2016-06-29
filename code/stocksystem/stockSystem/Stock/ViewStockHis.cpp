#include "ViewStockHis.h"
#include "ui_ViewStockHis.h"

ViewStockHis::ViewStockHis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewStockHis)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);

    QFont font = ui->label2->font();
    font.setPointSize(13);
    font.setBold(true);
    ui->label2->setFont(font);

    StockAccount *bac = new StockAccount;// = new BankAccount;
    QString hist = QString::fromStdString(bac->showTransHistory());
    QLabel *his = new QLabel(hist);
    ui->s->setWidget(his);

    bac->~StockAccount();

}

ViewStockHis::~ViewStockHis()
{
    delete ui;
}

void ViewStockHis::on_pushButton_clicked()
{
    StockWindow *sw = new StockWindow;
    this->close();
    this->~ViewStockHis();
    sw->show();
}
