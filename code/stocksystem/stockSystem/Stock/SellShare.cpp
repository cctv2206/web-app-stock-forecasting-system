#include "SellShare.h"
#include "ui_SellShare.h"

SellShare::SellShare(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellShare)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

SellShare::~SellShare()
{
    delete ui;
}

void SellShare::on_pushButton_clicked()
{
    StockWindow *bw = new StockWindow;
    this->close();
    this->~SellShare();
    bw->show();
}

void SellShare::on_Sell_clicked()
{
    StockAccount *sa = new StockAccount;
    double min = ui->min->text().toDouble();
    int shell =ui->shell->text().toInt();
    string stock = ui->stock->text().toStdString();
    int condition = sa->sellShares(shell, stock, min);
    QMessageBox *buy = new QMessageBox;
    if(condition == 0)
        buy->setText("Sell Fail! Not found stock " +  ui->stock->text() + " in your account");
    else if(condition ==1)
        buy->setText("Sell Fail! Price per share of stock " +  ui->stock->text() +" lower than min limit " + ui->min->text() );
    else if(condition == 2)
        buy->setText("Sell Successfully Stock " + ui->stock->text() +"  "+ui->shell->text() +" shares in total $" + QString::number(shell*min)  );
    buy->show();
//    buy->~QMessageBox();
    sa->~StockAccount();
}
