#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsRectItem>
#include "board.h"

class CustomGraphics : public QGraphicsScene
{
public:
    CustomGraphics(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    CustomGraphics();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QList<QGraphicsItem*> list;
    void setBoard(Board* board);
private:
    Board* m_board;
};

#endif // BOARDVIEW_H
