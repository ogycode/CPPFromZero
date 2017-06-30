#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //Переопределенный функция которая срабатывает при закрытии окна
    void closeEvent(QCloseEvent *);

private slots:
    //Слот который будет принимать сигнал от кликания
    //на иконку приложения в трее
    void iconTrayClick(QSystemTrayIcon::ActivationReason reason);

private:
    Ui::MainWindow *ui;

    //Обьект иконки в трее
    QSystemTrayIcon *iconTray;
};

#endif // MAINWINDOW_H
