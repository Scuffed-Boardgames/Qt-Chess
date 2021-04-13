#include "boardview.h"
#include <QList>



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
        return;
    }
    list.append(this->selectedItems());
    int x1 = list[0]->x()/100;
    int y1 = list[0]->y()/100;
    int x2 = list[1]->x()/100;
    int y2 = list[1]->y()/100;
    error test = m_board->makeMove(x1, y1, x2, y2);
    if(test != error::none){
        list.clear();
        return;
    }
    QList<QGraphicsItem*> child = list[0]->childItems();
    list[0]->childItems().clear();
    child[0]->setParentItem(list[1]);
    list.clear();
}

void CustomGraphics::setBoard(Board* board){
   m_board = board;
}
