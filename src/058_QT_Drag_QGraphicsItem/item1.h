#ifndef ITEM1_H
#define ITEM1_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QApplication>

class Item1 : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    QPointF shiftMouseCoords;

public:
    explicit Item1(QObject *parent = 0);
    ~Item1();

private:
    //Переопределяем методы отрисовки для рисования
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //переопределяем события мыши для перетаскивания
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // ITEM1_H
