#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT

private:
    QPointF prevPoint;          //координаты предыдущей точки

public:
    explicit PaintScene(QObject *parent = 0);
    ~PaintScene();

private:
    //для рисования используем события мышши
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
};

#endif // PAINTSCENE_H
