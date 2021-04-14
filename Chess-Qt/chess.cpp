#include "chess.h"
#include <QGridLayout>
#include <QVBoxLayout>


chess::chess(QWidget *parent, Board* board) : QWidget(parent){
    m_blackNext = 0;
    m_whiteNext = 0;
    QBrush brushgrey;
    brushgrey.setColor(Qt::gray);
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushwhite;
    brushwhite.setColor(Qt::white);
    brushwhite.setStyle(Qt::SolidPattern);
    scene = new CustomGraphics(0,0,800,800);
    scene->setBoard(board);
    view = new QGraphicsView((QGraphicsScene*)scene);

    int counter = 0;
    for (int i = -3; i < -1; ++i) {
        for (int j =2; j < 7; ++j) {
            QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0,100,100);
            rect->moveBy(100*i, 100*j-50);
            rect->setBrush(brushwhite);
            whiteOut[counter] = rect;
            scene->addItem(rect);
            ++counter;
        }
    }
    counter = 0;
    for (int i = 9; i < 11; ++i) {
        for (int j =2; j < 7; ++j) {
           QGraphicsRectItem* rect2 = new QGraphicsRectItem(0, 0,100,100);
           rect2->moveBy(100*i,100*j-50);
           rect2->setBrush(brushgrey);
           blackOut[counter] = rect2;
           scene->addItem(rect2);
           ++counter;
        }
    }
    for (int i =0; i < 8; ++i) {
        for (int j =0; j < 8; ++j) {
            QGraphicsRectItem* rect = new QGraphicsRectItem(0, 0,100,100);
            rect->moveBy(100*i,100*j);
            rect->setFlag(QGraphicsItem::ItemIsSelectable, true);
            if((i % 2 + j % 2)%2 == 0)
                rect->setBrush(brushgrey);
            else
                rect->setBrush(brushwhite);
            tiles[i][7-j] = rect;
            scene->addItem(rect);
        }
    }

    for (int i = 0; i < 8; ++i) {
        blackpieces[i] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_pdt80.png"), tiles[i][6]);
    }
    blackpieces[8] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_rdt80.png"), tiles[0][7]);
    blackpieces[9] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_rdt80.png"), tiles[7][7]);
    blackpieces[10] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_ndt80.png"), tiles[1][7]);
    blackpieces[11] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_ndt80.png"), tiles[6][7]);
    blackpieces[12] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_bdt80.png"), tiles[2][7]);
    blackpieces[13] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_bdt80.png"), tiles[5][7]);
    blackpieces[14] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_qdt80.png"), tiles[3][7]);
    blackpieces[15] = new QGraphicsPixmapItem(QPixmap(":/piece/Black/Chess_kdt80.png"), tiles[4][7]);
    for (int i = 0; i < 8; ++i) {
        whitepieces[i] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_plt80.png"),(QGraphicsItem*)tiles[i][1]);
    }
    whitepieces[8] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_rlt80.png"), tiles[0][0]);
    whitepieces[9] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_rlt80.png"), tiles[7][0]);
    whitepieces[10] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_nlt80.png"), tiles[1][0]);
    whitepieces[11] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_nlt80.png"), tiles[6][0]);
    whitepieces[12] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_blt80.png"), tiles[2][0]);
    whitepieces[13] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_blt80.png"), tiles[5][0]);
    whitepieces[14] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_qlt80.png"), tiles[3][0]);
    whitepieces[15] = new QGraphicsPixmapItem(QPixmap(":/piece/White/Chess_klt80.png"), tiles[4][0]);
    for(int i = 0; i < 16; ++i){
        blackpieces[i]->moveBy(10,10);
        whitepieces[i]->moveBy(10,10);
    }
    m_turn = 1;
    scene->setTurn(m_turn);
    toptext = new QLabel("Turn: 1 | Move: White");
    QVBoxLayout *mainLayout = new  QVBoxLayout;
    mainLayout->addWidget(toptext, 0);
    mainLayout->addWidget(view, 1);
    setLayout(mainLayout);
}

void chess::updateText(){
    ++m_turn;
    scene->setTurn(m_turn);
    QString colour;
    if(m_turn % 2 == 0)
        colour = "Black";
    else
        colour = "White";
    QString text = QString("Turn: ") + QString::number(m_turn) + QString(" | Move: ") + colour;
    toptext->setText(text);
}
void chess::moveMade(){
    updateText();
}

CustomGraphics* chess::getScene(){
    return scene;
}

int chess::getTurn(){
    return m_turn;
}

void chess::removePiece(int x, int y, Colour colour){
    QList<QGraphicsItem*> child = tiles[x][y]->childItems();
    if (colour == Colour::white){
        child[0]->setParentItem(whiteOut[m_whiteNext]);
        ++m_whiteNext;
    }else{
        child[0]->setParentItem(blackOut[m_blackNext]);
        ++m_blackNext;
    }
}

void chess::gameEnded(Colour colour){
    QString text;
    if (colour == Colour::white){
        text = QString("White has won in ") + QString::number(m_turn) + QString(" turns!");
    }else{
        text = QString("Black has won in ") + QString::number(m_turn) + QString(" turns!");
    }
    toptext->setText(text);

    for (int i =0; i < 8; ++i) {
        for (int j =0; j < 8; ++j) {
            tiles[i][j]->setFlag(QGraphicsItem::ItemIsSelectable, false);
        }
    }
}
