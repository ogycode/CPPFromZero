#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Косметическая подготовка приложения
    this->resize(640,640);                                  // Устанавливаем размеры окна приложения
    this->setFixedSize(640,640);

    scene = new QGraphicsScene(this);                       // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);     // настраиваем индексацию элементов

    ui->graphicsView->resize(600,600);                      // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);                      // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);         // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,500,500);                       // Устанавливаем размер сцены

    connect(ui->btnAdd1,SIGNAL(clicked()),this,SLOT(BtnItem1Click()));
    connect(ui->btnAdd2,SIGNAL(clicked()),this,SLOT(BtnItem2Click()));
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

//Функция для озвращения рандомного числа в диапазоне от а до b
int MainWindow::RandomBetween(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}

/*
 * Данный метод добавляет на сцену квадрат в котором
 * переопределеный методы события мыши для реализации
 * перетаскивания, иногда это полезно
*/
void MainWindow::BtnItem1Click()
{
    Item1 *item = new Item1();                                   // Создаём графический элемента
    item->setPos(RandomBetween(30, 470), RandomBetween(30,470)); // Устанавливаем случайную позицию элемента
    scene->addItem(item);                                        // Добавляем элемент на графическую сцену
}

/*
 * Данный метод добавляет на сцену квадрат в котором
 * события миши не переопределены, а перетаскивания
 * осуществляется стандратными методами установкой
 * флага QGraphicsItem::ItemIsMovable
*/
void MainWindow::BtnItem2Click()
{
    Item2 *item = new Item2();                                   // Создаём графический элемента
    item->setFlag(QGraphicsItem::ItemIsMovable);                 //Устанавливаем флаг, что итем перемещаемый
    item->setPos(RandomBetween(30, 470), RandomBetween(30,470)); // Устанавливаем случайную позицию элемента
    scene->addItem(item);                                        // Добавляем элемент на графическую сцену
}

