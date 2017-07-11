#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>

class MyGraphicView : public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene *scene;                  //Сцена для отрисовки
    QGraphicsItemGroup *group1;             //Первая группа
    QGraphicsItemGroup *group2;             //Вторая группа
    QTimer *timer;                          //Таймер для задержки отрисовки т.к. родительскому окну нужно время,
                                            //чтобы передавать коректные данные ширины и высоты
public:
    explicit MyGraphicView(QWidget *parent = 0);
    ~MyGraphicView();

private slots:
    void timerAlarm();                          //Слот  для обратботчика таймера, в нем будет перерисовыватся виджет

private:
    void resizeEvent(QResizeEvent *e);                      //Перегружаем событие изменение размера окна
    void deleteItemsFromGroup(QGraphicsItemGroup *group);   //Метод удаления элементов группы
};

#endif // MYGRAPHICVIEW_H
