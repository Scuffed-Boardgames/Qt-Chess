#ifndef CHESS_H
#define CHESS_H

#include <QGraphicsView>
#include <QWidget>
#include <QLabel>
#include "boardview.h"


class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = nullptr, Board* board = nullptr);
    CustomGraphics* getScene();
    int getTurn();
public slots:
    void moveMade();
    void removePiece(int x, int y, Colour colour);
private:
    CustomGraphics* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* blackpieces[16];
    QGraphicsPixmapItem* whitepieces[16];
    QGraphicsRectItem* tiles[8][8];
    QGraphicsRectItem* whiteOut[10];
    QGraphicsRectItem* blackOut[10];
    QLabel* toptext;
    int m_blackNext;
    int m_whiteNext;
    int m_turn;
    void updateText();
};

#endif // CHESS_H
