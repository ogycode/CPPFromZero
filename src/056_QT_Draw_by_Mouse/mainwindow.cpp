#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ps = new PaintScene();              //установка сцены
    ui->graphicsView->setScene(ps);

    timer = new QTimer();

    //конектим таймер к слоты
    connect(timer, &QTimer::timeout, this, &MainWindow::TimerTick);

    //запускаем таймер
    //60 FPS > 1000 / 60 = 16
    //30 FPS > 1000 / 30 = 32
    timer->start(32);
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ps;
    delete ui;
}

void MainWindow::TimerTick()
{
    timer->stop();
    ps->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    timer->start(32);
    QWidget::resizeEvent(e);
}
