#include "bankwindow.h"
#include "ui_BankWindow.h"
#include <QDesktopWidget>
BankWindow::BankWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::BankWindow)
{

   ui->setupUi(this);
   QPixmap pix = QPixmap("img.jpg").scaled(this->size());
   QPalette pal(this->palette());
   pal.setBrush(QPalette::Background,QBrush(pix));
   this->setPalette(pal);
   this->setWindowOpacity(0.9);
   /*
   QPixmap pi("IMG_2159");
   QIcon ButtonICON(pi);
   ui->deposit->setIcon(ButtonICON);
   ui->deposit->setIconSize(pi.rect().size());
   */
}

BankWindow::~BankWindow()
{
    delete ui;
}

void BankWindow::returnMain(){
    MainWindow *w = new MainWindow;
    w->show();
    this->close();

}

void BankWindow::on_ViewBal_clicked()
{
    BW_ViewBalance *bv = new BW_ViewBalance;
    bv->show();
    this->close();
}

void BankWindow::on_deposit_clicked()
{
    BankDeposit *bd = new BankDeposit;
    bd->show();
    this->close();
}

void BankWindow::on_withdrawl_clicked()
{
    BankWithdraw *bw = new BankWithdraw();
    bw->show();
    this->close();
}

void BankWindow::on_pushButton_4_clicked()
{
   BankHis *bh = new BankHis();
   bh->show();
    this->close();
}
