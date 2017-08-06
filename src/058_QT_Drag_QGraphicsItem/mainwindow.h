#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "item1.h"
#include "item2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int RandomBetween(int a, int b);

public slots:
    void BtnItem1Click();
    void BtnItem2Click();
};

#endif // MAINWINDOW_H
