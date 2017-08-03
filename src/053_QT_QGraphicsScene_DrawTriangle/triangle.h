#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QGraphicsItem>
#include <QPainter>


class Triangle : public QGraphicsItem
{
public:
    Triangle();
    ~Triangle();

protected:
    QRectF boundingRect() const;      //переопределяем виртуальный метод который возвращает область
                                      //в которой нахдится триугольник

    //переопределяем метод для отрисовки тригольника
    void paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w);
};

#endif // TRIANGLE_H
