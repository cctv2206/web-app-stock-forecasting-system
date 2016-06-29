#ifndef SELLSHARE_H
#define SELLSHARE_H

#include <QWidget>
#include <stockwindow.h>

namespace Ui {
class SellShare;
}

class SellShare : public QWidget
{
    Q_OBJECT

public:
    explicit SellShare(QWidget *parent = 0);
    ~SellShare();

private slots:
    void on_pushButton_clicked();

    void on_Sell_clicked();

private:
    Ui::SellShare *ui;
};

#endif // SELLSHARE_H
