#include "item1.h"

Item1::Item1(QObject *parent) : QObject(parent), QGraphicsItem() {}
Item1::~Item1() {}

QRectF Item1::boundingRect() const
{
    return QRectF(-30,-30,60,60);
}

void Item1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,60,60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Item1::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
       /* Устанавливаем позицию графического элемента
        * в графической сцене, транслировав координаты
        * курсора внутри графического элемента
        * в координатную систему графической сцены
        */
    this->setPos(mapToScene(event->pos() + shiftMouseCoords));
}

void Item1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Удаляем при нажатии правой кнопки мыши
    if (QApplication::mouseButtons() == Qt::RightButton)
        this->deleteLater();

    //При нажатии мышью на графический элемент заменяем курсор на руку, которая держит этот элемента
    shiftMouseCoords = this->pos() - mapToScene(event->pos());
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event)
}

void Item1::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //При отпускании мышью элемента заменяем на обычный курсор стрелку
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
