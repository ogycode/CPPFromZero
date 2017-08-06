#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

private:
    QTimer *timer;          //таймер для пролистывания кадров
    QPixmap *img;           //обьект в который будет помещен спрайт
    int currentFrame;       //координата Х с которого начинается текущий кадр
    int width;              //ширина
    int height;             //высота
    int frameCount;         //количество фреймов в спрайте

public:
    explicit Sprite(QString sprite,int frameCount, int delay, QObject *parent = 0);
    ~Sprite();

public:
    void SetFrameSize(int w, int h);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private slots:
    void NextFrame();
};

#endif // SPRITE_H
