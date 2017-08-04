#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
     * Настройка сигналов и слотов в редакторе форм
     * событие клика вызывет метод repaint()
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter paint(this);           //обьект отрисовщика

    //устанавливаем кисть
    paint.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

    //проверяем какой чекбокс выбран
    if(ui->rbtnRed->isChecked())
    {
        paint.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        paint.drawEllipse(100, 50, 150, 150);
    }
    else if(ui->rbtnGreen->isChecked())
    {
        paint.setBrush(QBrush(Qt::green, Qt::SolidPattern));
        paint.drawEllipse(100, 50, 150, 150);
    }
    else if(ui->rbtnBlue->isChecked())
    {
        paint.setBrush(QBrush(Qt::blue, Qt::SolidPattern));
        paint.drawEllipse(100, 50, 150, 150);
    }
    //если ничего не выбрано отрисовываем белый круг
    else
    {
        paint.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        paint.drawEllipse(100, 50, 150, 150);
    }
}
