#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>

#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    //Обьект базы данных и модель представления для таблиц
    Database *db;
    QSqlRelationalTableModel *mainModel;
    QSqlRelationalTableModel *deviceModel;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void SetupMainModel(const QString &name, const QStringList &headers);
    void SetupDeviceModel(const QString &name, const QStringList &headers);
    void SetupUI();
};

#endif // MAINWINDOW_H
