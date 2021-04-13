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
private:
    CustomGraphics* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* blackpieces[16];
    QGraphicsPixmapItem* whitepieces[16];
    QGraphicsRectItem* tiles[8][8];
    QLabel* toptext;
    int m_turn;
    void updateText();

};

#endif // CHESS_H
