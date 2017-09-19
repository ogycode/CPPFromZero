#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindowsecond.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    MainWindowSecond *sc;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void btnCallSecontClick();      //событие клика по кнопке для открытия второго окна
};

#endif // MAINWINDOW_H
