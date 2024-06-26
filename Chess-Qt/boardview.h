#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsRectItem>
#include "board.h"
#include "ai.h"
#include <QObject>

class BoardView : public QGraphicsScene
{
    Q_OBJECT

public:
    BoardView(qreal x, qreal y, qreal width, qreal height, std::shared_ptr<Board> board, QObject *parent = nullptr);
    BoardView();

    void setTurn(int turn);
signals:
    void madeMove();

private:
    std::shared_ptr<Board> m_board;
    QList<QGraphicsItem*> list;
    int m_turn;

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setGreen(QGraphicsRectItem* rect);
    void setBack(QGraphicsRectItem* rect);
};

#endif // BOARDVIEW_H
