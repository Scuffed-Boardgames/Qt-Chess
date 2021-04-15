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
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setGreen(QGraphicsRectItem* rect);
    void setBack(QGraphicsRectItem* rect);
    QList<QGraphicsItem*> list;
    void setTurn(int turn);
signals:
    void madeMove();

private:
    std::shared_ptr<Board> m_board;
    int m_turn;
};

#endif // BOARDVIEW_H
