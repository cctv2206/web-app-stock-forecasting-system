#include "stockwindow.h"
#include "ui_StockWindow.h"

StockWindow::StockWindow(QWidget *parent) :
    QMainWindow(parent),
   ui(new Ui::StockWindow)
{
   ui->setupUi(this);
   QPixmap pix = QPixmap("img.jpg").scaled(this->size());
   QPalette pal(this->palette());
   pal.setBrush(QPalette::Background,QBrush(pix));
   this->setPalette(pal);
   this->setWindowOpacity(0.9);
}

StockWindow::~StockWindow()
{
    delete ui;
}
void StockWindow::returnMain(){
    MainWindow *w = new MainWindow;
    w->show();
    this->close();
    this->~StockWindow();
}

void StockWindow::on_ViewPrice_clicked()
{
    ViewPrice *vp = new ViewPrice;
    vp->show();
    this->close();
    this->~StockWindow();
}

void StockWindow::on_BuyShare_clicked()
{
    BuyShell *bs = new BuyShell;
    bs->show();
    this->close();
    this->~StockWindow();

}

void StockWindow::on_SellShare_clicked()
{
    SellShare *ss = new SellShare;
    ss->show();
    this->close();
    this->~StockWindow();
}

void StockWindow::on_viewHist_clicked()
{
    ViewStockHis *vs = new ViewStockHis;
    vs->show();
    this->close();
    this->~StockWindow();
}

void StockWindow::on_ViewPortfo_clicked()
{
    ViewPortf *vp = new ViewPortf;
    vp->show();
    this->close();
    this->~StockWindow();
}
