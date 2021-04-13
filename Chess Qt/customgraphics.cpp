#include "customgraphics.h"
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
//        this->clearSelection();
    }
    list.append(this->selectedItems());
    QList<QGraphicsItem*> child = list[0]->childItems();
    list[0]->childItems().clear();
    child[0]->setParentItem(list[1]);
    list.clear();
}
