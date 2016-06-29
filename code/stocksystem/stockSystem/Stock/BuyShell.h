#ifndef BUYSHELL_H
#define BUYSHELL_H

#include <QWidget>
#include <stockwindow.h>

namespace Ui {
class BuyShell;
}

class BuyShell : public QWidget
{
    Q_OBJECT

public:
    explicit BuyShell(QWidget *parent = 0);
    ~BuyShell();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::BuyShell *ui;
};

#endif // BUYSHELL_H
