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
    void setGreen(QGraphicsRectItem* rect);
    void setBack(QGraphicsRectItem* rect);
    QList<QGraphicsItem*> list;
    void setBoard(Board* board);
    void setTurn(int turn);
    void setEnded();
signals:
    void madeMove();

private:
    Board* m_board;
    int m_turn;
    bool m_gameEnded;
};

#endif // BOARDVIEW_H
