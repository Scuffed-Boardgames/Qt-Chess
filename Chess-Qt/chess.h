#ifndef CHESS_H
#define CHESS_H

#include <QGraphicsView>
#include <QWidget>
#include "boardview.h"


class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = nullptr, Board* board = nullptr);
    void show();

signals:
private:
    CustomGraphics* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* blackpieces[16];
    QGraphicsPixmapItem* whitepieces[16];
    QGraphicsRectItem* tiles[8][8];

};

#endif // CHESS_H
