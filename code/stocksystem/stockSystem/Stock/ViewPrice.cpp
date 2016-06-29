#include "ViewPrice.h"
#include "ui_ViewPrice.h"

ViewPrice::ViewPrice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewPrice)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

ViewPrice::~ViewPrice()
{
    delete ui;
}


void ViewPrice::on_view_clicked()
{
    QString stock = ui->input->text();

    StockAccount *sa = new StockAccount();

//    sa->showallprice();

    double stockprice = sa->showStockPrice(stock.toStdString());//return price double
    if(stockprice == 0)
        ui->price->setText("Not found stock " + stock);
    else{
        QString price = QString::number(stockprice);
        ui->price->setText(price);

    }

//     sa->~StockAccount();
}

void ViewPrice::on_pushButton_clicked()
{
    StockWindow *sw = new StockWindow;
    this->close();
    this->~ViewPrice();
    sw->show();
}
