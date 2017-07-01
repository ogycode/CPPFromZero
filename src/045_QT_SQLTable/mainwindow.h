#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>

#include "database.h"

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

private:
    Ui::MainWindow *ui;

    //Свойства, таблица и модель предстваления
    Database *myDB;
    QSqlTableModel *dbModel;

private:
    //Методы формируют модель и внешний вид таблицы
    void SetupModel(const QString &name, const QStringList &headers);
    void CreateUI();
};

#endif // MAINWINDOW_H
