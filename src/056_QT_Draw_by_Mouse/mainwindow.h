#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    PaintScene *ps;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void resizeEvent(QResizeEvent *e);

private slots:
    void TimerTick();
};

#endif // MAINWINDOW_H
