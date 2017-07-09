#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include <QMessageBox>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QShortcut *f11;
    QShortcut *ctrm;
    QShortcut *custom;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void goFullscreen();
    void showMessage();
    void btnSetNewClick();
    void SetEnableKeySec();
};

#endif // MAINWINDOW_H
