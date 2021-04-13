#include "chess.h"

#include <QPoint>


chess::chess(QWidget *parent) : QWidget(parent){
    QBrush brushgrey;
    brushgrey.setColor(Qt::gray);
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushwhite;
    brushwhite.setColor(Qt::white);
    brushwhite.setStyle(Qt::SolidPattern);
    scene = new CustomGraphics(0,0,800,800);
    view = new QGraphicsView((QGraphicsScene*)scene);

    QGraphicsRectItem* tiles[8][8];
    for (int i =0; i < 8; ++i) {
        for (int j =0; j < 8; ++j) {
            QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0,100,100);
            rect->moveBy(100*i,100*j);
            rect->setFlag(QGraphicsItem::ItemIsSelectable, true);
            if((i % 2 + j % 2)%2 == 0)
                rect->setBrush(brushgrey);
            else
                rect->setBrush(brushwhite);
            tiles[i][j] = rect;
            scene->addItem(rect);
        }
    }

    QGraphicsPixmapItem* blackpawns[8];
    QGraphicsPixmapItem* whitepawns[8];
    for (int i = 0; i < 8; ++i) {
        QGraphicsPixmapItem* blackPawn = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_pdt80.png"), tiles[i][1]);
        blackPawn->moveBy(10,10);
        blackPawn->setZValue(99999999);
        blackPawn->setFlag(QGraphicsItem::ItemIsMovable);
        blackpawns[i] = blackPawn;
        scene->addItem(blackPawn);
    }
    for (int i = 0; i < 8; ++i) {
        QGraphicsPixmapItem* whitePawn = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_plt80.png"),(QGraphicsItem*)tiles[i][6]);
        whitePawn->moveBy(10,10);
        whitePawn->setZValue(999999999);
        whitePawn->setFlag(QGraphicsItem::ItemIsMovable);
        whitepawns[i] = whitePawn;
        scene->addItem(whitePawn);
    }
}

void chess::show(){
    view->show();
}


