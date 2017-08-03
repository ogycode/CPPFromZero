#include "triangle.h"

Triangle::Triangle() : QGraphicsItem() {}
Triangle::~Triangle(){}

QRectF Triangle::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void Triangle::paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w)
{
    //используем класс полигона для отисовки триугольника
    QPolygon polygon;
    //Помещаем точки в полигон, таким образом "строим" его
    polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
    p->setBrush(Qt::red);           //Устанавливаем цвет триугольника
    p->drawPolygon(polygon);        //Отрисовываем триугольник

    Q_UNUSED(o);
    Q_UNUSED(w);
}
