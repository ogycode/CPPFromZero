#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //определяем виртуальный метод родительского класса
    //для отрисовки виджета
    void paintEvent(QPaintEvent *e);

};

#endif // MAINWINDOW_H
