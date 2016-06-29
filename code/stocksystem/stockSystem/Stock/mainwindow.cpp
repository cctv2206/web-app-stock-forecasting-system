#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix = QPixmap("img.jpg").scaled(this->size());
    QPalette pal(this->palette());
    pal.setBrush(QPalette::Background,QBrush(pix));
    this->setPalette(pal);
    this->setWindowOpacity(0.9);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Stock_clicked()
{
    StockWindow *sw = new StockWindow;
    sw->show();
    this->close();
    this->~MainWindow();
}

void MainWindow::on_Bank_clicked()
{
    BankWindow *bw = new BankWindow;
    bw->show();
    this->close();
    this->~MainWindow();
}

