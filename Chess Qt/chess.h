#ifndef CHESS_H
#define CHESS_H

#include <QGraphicsView>
#include <QWidget>
#include "customgraphics.h"


class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = nullptr);
    void show();

signals:
private:
    CustomGraphics* scene;
    QGraphicsView* view;

};

#endif // CHESS_H
