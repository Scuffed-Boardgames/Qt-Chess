#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsRectItem>
#include "board.h"
#include <QObject>

class CustomGraphics : public QGraphicsScene
{
    Q_OBJECT

public:
    CustomGraphics(qreal x, qreal y, qreal width, qreal height, QObject *parent = nullptr);
    CustomGraphics();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    QList<QGraphicsItem*> list;
    void setBoard(Board* board);
    void setTurn(int turn);
signals:
    void madeMove();

private:
    Board* m_board;
    int m_turn;
};

#endif // BOARDVIEW_H
