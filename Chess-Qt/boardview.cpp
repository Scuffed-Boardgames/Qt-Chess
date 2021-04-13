#include "boardview.h"
#include <QList>
#include <QMessageBox>
#include <QTimer>


CustomGraphics::CustomGraphics(qreal x, qreal y, qreal width, qreal height, QObject *parent) : QGraphicsScene(x, y, width, height, parent)
{

}

CustomGraphics::CustomGraphics()
{

}

void CustomGraphics::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsScene::mouseReleaseEvent(event);
    if(list.length() == 0){
        list = this->selectedItems();
        setGreen((QGraphicsRectItem*)list[0]);
        return;
    }
    list.append(this->selectedItems());
    setGreen((QGraphicsRectItem*)list[1]);
    int x1 = list[0]->x()/100;
    int y1 = 7 - list[0]->y()/100;
    int x2 = list[1]->x()/100;
    int y2 = 7 - list[1]->y()/100;
    Colour colour;
    if(m_turn % 2 != 0)
        colour = Colour::white;
    else
        colour = Colour::black;
    error test = m_board->makeMove(x1, y1, x2, y2, colour);
    if(test != error::none){
        setBack((QGraphicsRectItem*)list[0]);
        setBack((QGraphicsRectItem*)list[1]);
        list.clear();
        return;
    }
    QList<QGraphicsItem*> child = list[0]->childItems();
    list[0]->childItems().clear();
    child[0]->setParentItem(list[1]);
    setBack((QGraphicsRectItem*)list[0]);
    setBack((QGraphicsRectItem*)list[1]);
    list.clear();
    emit madeMove();
}

void CustomGraphics::setBoard(Board* board){
   m_board = board;
}

void CustomGraphics::setTurn(int turn){
    m_turn = turn;
}

void CustomGraphics::setGreen(QGraphicsRectItem* rect){
    QBrush brushgreen;
    brushgreen.setColor(Qt::green);
    brushgreen.setStyle(Qt::SolidPattern);
    rect->setBrush(brushgreen);
}

void CustomGraphics::setBack(QGraphicsRectItem* rect){
    QBrush brushgrey;
    brushgrey.setColor(Qt::gray);
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushwhite;
    brushwhite.setColor(Qt::white);
    brushwhite.setStyle(Qt::SolidPattern);
    int x = rect->x()/100;
    int y = rect->y()/100;
    if ((x % 2 + y % 2)%2 == 0)
        rect->setBrush(brushgrey);
    else
        rect->setBrush(brushwhite);
}
