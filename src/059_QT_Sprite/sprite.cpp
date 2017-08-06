#include "sprite.h"

Sprite::Sprite(QString sprite, int count, int delay, QObject *parent) : QObject(parent), QGraphicsItem()
{
    width = 32;                 //ширина/высота кадра
    height = 32;
    frameCount = count;         //количество кадров
    currentFrame = 0;           //условная скорость анимации

    img = new QPixmap(sprite);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(NextFrame()));
    timer->start(delay);
}

Sprite::~Sprite()
{
    delete timer;
    delete img;
}

void Sprite::SetFrameSize(int w, int h)
{
    width = w;
    height = h;
}

QRectF Sprite::boundingRect() const
{
    return QRectF(0,0, width, height);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // 1. Координата Х куда помещается картинка
    // 2. Координата У куда помещается картинка
    // 3. Указатель на QPixmap
    // 4. Задаем область отрисовки, Х0 (начало)     Задается область которая будет отрисовыватся
    // 5. Задаем область отрисовки, У0 (начало)
    // 6. Задаем область отрисовки, Х1 (ширина)
    // 7. Задаем область отрисовки, У1 (высота)
    painter->drawPixmap(0,0, *img, currentFrame, 0, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Sprite::NextFrame()
{
    //каждый тик устанавливаем иксовую коородинату текущего фрейма
    currentFrame += width;
    //координата текущего фрема больше ширини спрайта обнуляем ее, начинаем с начала
    if (currentFrame >= width * frameCount )
        currentFrame = 0;
    //перерисовываем спрайт с новыми координатами
    this->update(0,0, width, height);
}
