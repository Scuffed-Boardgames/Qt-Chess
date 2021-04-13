#include "chess.h"
#include <QGridLayout>


chess::chess(QWidget *parent, Board* board) : QWidget(parent){
    QBrush brushgrey;
    brushgrey.setColor(Qt::gray);
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushwhite;
    brushwhite.setColor(Qt::white);
    brushwhite.setStyle(Qt::SolidPattern);
    scene = new CustomGraphics(0,0,800,800);
    scene->setBoard(board);
    view = new QGraphicsView((QGraphicsScene*)scene);


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

    for (int i = 0; i < 8; ++i) {
        blackpieces[i] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_pdt80.png"), tiles[i][1]);
    }
    blackpieces[8] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_rdt80.png"), tiles[0][0]);
    blackpieces[9] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_rdt80.png"), tiles[7][0]);
    blackpieces[10] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_ndt80.png"), tiles[1][0]);
    blackpieces[11] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_ndt80.png"), tiles[6][0]);
    blackpieces[12] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_bdt80.png"), tiles[2][0]);
    blackpieces[13] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_bdt80.png"), tiles[5][0]);
    blackpieces[14] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_qdt80.png"), tiles[3][0]);
    blackpieces[15] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_kdt80.png"), tiles[4][0]);
    for (int i = 0; i < 8; ++i) {
        whitepieces[i] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_plt80.png"),(QGraphicsItem*)tiles[i][6]);
    }
    whitepieces[8] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_rlt80.png"), tiles[0][7]);
    whitepieces[9] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_rlt80.png"), tiles[7][7]);
    whitepieces[10] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_nlt80.png"), tiles[1][7]);
    whitepieces[11] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_nlt80.png"), tiles[6][7]);
    whitepieces[12] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_blt80.png"), tiles[2][7]);
    whitepieces[13] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_blt80.png"), tiles[5][7]);
    whitepieces[14] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_qlt80.png"), tiles[3][7]);
    whitepieces[15] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_klt80.png"), tiles[4][7]);
    for(int i = 0; i < 16; ++i){
        blackpieces[i]->moveBy(10,10);
        whitepieces[i]->moveBy(10,10);
    }

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(view, 0, 0);
    setLayout(mainLayout);
}



