#ifndef CUSTOMGRAPHICS_H
#define CUSTOMGRAPHICS_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsRectItem>

class CustomGraphics : public QGraphicsScene
{
public:
    CustomGraphics(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    CustomGraphics();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QList<QGraphicsItem*> list;
};

#endif // CUSTOMGRAPHICS_H
