#include "item2.h"

Item2::Item2(QObject *parent) : QObject(parent), QGraphicsItem() {}
Item2::~Item2() {}

QRectF Item2::boundingRect() const
{
    return QRectF(-30,-30,60,60);
}

void Item2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::blue);
    painter->drawRect(-30,-30,60,60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
