#ifndef ITEM2_H
#define ITEM2_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Item2 : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Item2(QObject *parent = 0);
    ~Item2();

private:
    //Переопределяем методы отрисовки для рисования
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // ITEM2_H
