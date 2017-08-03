#include "mypoint.h"

MyPoint::MyPoint(QObject *parent) : QObject(parent), QGraphicsItem() {}

MyPoint::~MyPoint() {}

QRectF MyPoint::boundingRect() const
{
    //координаты по которым будет реагировать события клика
    return QRectF(0,0,100,100);
}

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(0, 0, 100, 100));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MyPoint::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //посылаем сигнал
    emit pointClick();

    //вызываем родительскую функцию
    QGraphicsItem::mousePressEvent(event);
}
