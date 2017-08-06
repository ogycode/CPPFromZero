#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();                   // Инициализируем графическую сцену
    ui->graphicsView->setScene(scene);              // Устанавливаем графическую сцену в graphicsView

    Sprite *s1 = new Sprite(":/coin",6,78,this);
    s1->SetFrameSize(96,96);                        //задаем размеры кадра

    scene->addItem(s1);                             // Помещаем на сцену новый объект спрайта
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}
