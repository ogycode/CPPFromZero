#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QMessageBox>
#include <QFile>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void btnBrowseOpenClick();      //Обработчик события, открыть файл
    void btnBrowseSaveClick();      //Сохранить в файл
    void btnReadClick();            //Считать с файла
    void btnSaveClick();            //Записать в фыйл
};

#endif // MAINWINDOW_H
