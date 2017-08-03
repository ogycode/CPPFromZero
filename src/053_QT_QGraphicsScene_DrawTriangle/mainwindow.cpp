#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Устанавливаем размер окна
    this->resize(600,600);
    //Устанавливаем фиксированый размер окна
    this->setFixedSize(600,600);

    scene = new QGraphicsScene();
    triangle = new Triangle();

    ui->graphicsView->setScene(scene);                          //Устанваливаем сцену
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    //Устанвливаем сглаживание
    //отключаем скроллы
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);                     //Установка области цсены
    scene->addLine(-250,0,250,0,QPen(Qt::black));               // Добавляем горизонтальную линию через центр
    scene->addLine(0,-250,0,250,QPen(Qt::black));               // Добавляем вертикальную линию через центр

    scene->addItem(triangle);                                   // Добавляем на сцену треугольник
    triangle->setPos(0,0);                                      // Устанавливаем треугольник в центр сцены
}

MainWindow::~MainWindow()
{
    delete ui;
    delete triangle;
    delete scene;
}
