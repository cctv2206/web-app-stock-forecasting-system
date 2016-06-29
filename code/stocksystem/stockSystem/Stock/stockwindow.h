#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <mainwindow.h>
#include <BuyShell.h>
#include <SellShare.h>
#include <ViewPortf.h>
#include <ViewPrice.h>
#include <ViewStockHis.h>
#include <StockAccount.h>
namespace Ui{
    class StockWindow;
}

class StockWindow : public QMainWindow
{
    Q_OBJECT
public:
     explicit StockWindow(QWidget *parent = 0 );
    ~StockWindow();
private slots:
    void returnMain();
    void on_ViewPrice_clicked();

    void on_BuyShare_clicked();

    void on_SellShare_clicked();

    void on_viewHist_clicked();

    void on_ViewPortfo_clicked();

private:
    Ui::StockWindow *ui;
};

#endif // STOCKWINDOW_H
