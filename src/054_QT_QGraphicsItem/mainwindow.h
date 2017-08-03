#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include "mypoint.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MyPoint *point;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //слот для обработки сигнала с точки
    void slotFromForm();
};

#endif // MAINWINDOW_H
