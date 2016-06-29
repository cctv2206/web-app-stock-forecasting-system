#ifndef VIEWSTOCKHIS_H
#define VIEWSTOCKHIS_H

#include <QWidget>
#include <stockwindow.h>

namespace Ui {
class ViewStockHis;
}

class ViewStockHis : public QWidget
{
    Q_OBJECT

public:
    explicit ViewStockHis(QWidget *parent = 0);
    ~ViewStockHis();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewStockHis *ui;
};

#endif // VIEWSTOCKHIS_H
