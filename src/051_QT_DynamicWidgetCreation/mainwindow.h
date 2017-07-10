#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    int numberOfButtons;                        //Количество добавленых кнопок

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void AddButtonClick();                      //Событие нажатия кнопки добавить кнопку
    void RemoveLastButtonClick();               //Удалить кнопку
    void AddedButtonClick();                    //Событие для добавленых кнопок
};

#endif // MAINWINDOW_H
