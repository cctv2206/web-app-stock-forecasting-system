#ifndef VIEWPRICE_H
#define VIEWPRICE_H

#include <QWidget>
#include <stockwindow.h>
namespace Ui {
class ViewPrice;
}

class ViewPrice : public QWidget
{
    Q_OBJECT

public:
    explicit ViewPrice(QWidget *parent = 0);
    ~ViewPrice();

private slots:

    void on_view_clicked();

    void on_pushButton_clicked();

private:
    Ui::ViewPrice *ui;
};

#endif // VIEWPRICE_H
