#ifndef VIEWPORTF_H
#define VIEWPORTF_H

#include <QWidget>
#include <stockwindow.h>

namespace Ui {
class ViewPortf;
}

class ViewPortf : public QWidget
{
    Q_OBJECT

public:
    explicit ViewPortf(QWidget *parent = 0);
    ~ViewPortf();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewPortf *ui;
};

#endif // VIEWPORTF_H
