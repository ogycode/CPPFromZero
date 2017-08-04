#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {}
PaintScene::~PaintScene() {}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    //рисуем линию по придыдущей точке
    addLine(prevPoint.x(),     prevPoint.y(),
            e->scenePos().x(), e->scenePos().y(),
            QPen(Qt::red, 10, Qt::SolidLine, Qt::RoundCap));

    //Обновляем придыдущую точку
    prevPoint = e->scenePos();
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    // При нажатии кнопки мыши рисуем эллипс
    addEllipse(e->scenePos().x() - 5, e->scenePos().y() - 5, 10, 10, QPen(Qt::NoPen), QBrush(Qt::red));
    //Обновляем придыдущую точку
    prevPoint = e->scenePos();
}
