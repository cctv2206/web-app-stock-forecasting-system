#ifndef BW_VIEWBALANCE_H
#define BW_VIEWBALANCE_H

#include <QWidget>
#include <bankwindow.h>
namespace Ui {
class BW_ViewBalance;
}

class BW_ViewBalance : public QWidget
{
    Q_OBJECT

public:
    explicit BW_ViewBalance(QWidget *parent = 0);
    ~BW_ViewBalance();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BW_ViewBalance *ui;
};

#endif // BW_VIEWBALANCE_H
