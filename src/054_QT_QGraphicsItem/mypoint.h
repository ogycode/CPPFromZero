#ifndef MYPOINT_H
#define MYPOINT_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

//Чтобы работыли сигналы и слоты наследуемся от QObject
class MyPoint : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals:
    //сигнал который будет посылатся в случае клика мышью
    void pointClick();

public:
    explicit MyPoint(QObject *parent = 0);
    ~MyPoint();

protected:
    //переопределяем метод нажатия мишью, для его перехвата
    void mousePressEvent(QGraphicsSceneMouseEvent *e);

private:
    //это виртуальные методы (их необходимо реализовать)
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MYPOINT_H
