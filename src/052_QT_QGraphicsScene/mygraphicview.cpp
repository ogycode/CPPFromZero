#include "mygraphicview.h"

MyGraphicView::MyGraphicView(QWidget *parent) : QGraphicsView(parent)
{
    //Настройка виджета
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);             //Отключаем скролл по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);               //Отключаем скролл по вертикали
    this->setAlignment(Qt::AlignCenter);                                    //Привязываем расположение к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    //Растяшиваем содержимое по виджету

    //Минимальные значения ширины/высоты
    this->setMinimumWidth(100);
    this->setMinimumHeight(100);

    scene = new QGraphicsScene();               //Инициализируем сцену
    this->setScene(scene);                      //Устанавливаем сцену в виджет

    group1 = new QGraphicsItemGroup();          //Инициализируем группы
    group2 = new QGraphicsItemGroup();

    scene->addItem(group1);                     //Добавляем группы к сцене
    scene->addItem(group2);

    timer = new QTimer();                       //Инициализируем таймер
    timer->start(50);                           //Запускаем таймер на 50 милисек

    connect(timer, SIGNAL(timeout()),this,SLOT(timerAlarm()));
}

MyGraphicView::~MyGraphicView()
{
    delete timer;
    delete group1;
    delete group2;
    delete scene;
}

void MyGraphicView::resizeEvent(QResizeEvent *e)
{
    this->timer->start(50);             //Как сработало событие запускаем таймер
    QGraphicsView::resizeEvent(e);      //и вызываем родительское событие
}

void MyGraphicView::deleteItemsFromGroup(QGraphicsItemGroup *group)
{
    //Перебираем все элементы в сцене и если они принадлежат группе
    //то удаляем их
    for(auto item : this->scene->items(group->boundingRect()))
        if(item->group() == group)
            delete item;
}

void MyGraphicView::timerAlarm()
{
    this->deleteItemsFromGroup(group1);         //Удаляем со сцены все элементы
    this->deleteItemsFromGroup(group2);         //перед новой отрисовкой

    int w = this->width();                      //Определяем ширины и высоту виджета
    int h = this->height();

    scene->setSceneRect(0,0,w,h);               //Устанавливаем размер сцены

    /*Тут отрисовка*/

    QPen red(Qt::red);
    QPen black(Qt::black);

    //Рисуем черный прямоугольник
    group1->addToGroup(scene->addLine(20,20,w-20,20,black));
    group1->addToGroup(scene->addLine(w-20,20,w-20,h-20,black));
    group1->addToGroup(scene->addLine(w-20,h-20,20,h-20,black));
    group1->addToGroup(scene->addLine(20,h-20,20,20,black));

    //Рисуем красный квадрат
    int side = h > w ? w - 60 : h - 60;
    int centerX = w/2;
    int centerY = h/2;

    group1->addToGroup(scene->addLine(centerX - side/2, centerY - side/2, centerX + side/2, centerY - side/2,red));
    group1->addToGroup(scene->addLine(centerX + side/2, centerY - side/2, centerX + side/2, centerY + side/2,red));
    group1->addToGroup(scene->addLine(centerX + side/2, centerY + side/2, centerX - side/2, centerY + side/2,red));
    group1->addToGroup(scene->addLine(centerX - side/2, centerY + side/2, centerX - side/2, centerY - side/2,red));
}
