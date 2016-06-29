#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <bankwindow.h>
#include <stockwindow.h>
#include <QPalette>
#include <QPixmap>
#include <QFont>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_Stock_clicked();

    void on_Bank_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
