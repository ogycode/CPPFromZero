#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //При первом запуске программы поместим текущее время в лейбл
    ui->lblTime->setText(QTime::currentTime().toString("hh:mm:ss"));

    //Инициализируем таймер:
    //1 Связываем его со слотом
    //2 Запускаем с указанием интревала (1000 милисек - 1 сек)
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(slotTimerTick()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

//Срабатывает при истичении интревала таймера
void MainWindow::slotTimerTick()
{
    ui->lblTime->setText(QTime::currentTime().toString("hh:mm:ss"));
}
