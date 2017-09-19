#ifndef MAINWINDOWSECOND_H
#define MAINWINDOWSECOND_H

#include <QMainWindow>

namespace Ui {
class MainWindowSecond;
}

class MainWindowSecond : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindowSecond *ui;

public:
    explicit MainWindowSecond(QWidget *parent = 0);
    ~MainWindowSecond();

signals:
    void firstWindow();                  //сигнл для вызова первого окна

private slots:
    void btnCallFirstClick();       //событие клика по кнопке
};

#endif // MAINWINDOWSECOND_H
