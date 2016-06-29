#ifndef BANKHIS_H
#define BANKHIS_H

#include <QWidget>
#include <bankwindow.h>
#include <BankAccount.h>
#include <QScrollArea>
namespace Ui {
class BankHis;
}

class BankHis : public QWidget
{
    Q_OBJECT

public:
    explicit BankHis(QWidget *parent = 0);
    ~BankHis();

private slots:

    void on_pushButton_clicked();

private:
    Ui::BankHis *ui;
};

#endif // BANKHIS_H
