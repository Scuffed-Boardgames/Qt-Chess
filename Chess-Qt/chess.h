#ifndef CHESS_H
#define CHESS_H

#include <QGraphicsView>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include "boardview.h"
#include "game.h"


class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = nullptr, Game* game = nullptr);
    CustomGraphics* getScene();
    int getTurn();
    QPushButton* getButton(int buttonNr);
    void reset();
public slots:
    void moveMade();
    void removePiece(int x, int y, Colour colour);
    void gameEnded(Colour colour);
private:
    Game* m_game;
    void setPieces();
    CustomGraphics* scene;
    QGraphicsView* view;
    QGraphicsPixmapItem* blackpieces[16];
    QGraphicsPixmapItem* whitepieces[16];
    QGraphicsRectItem* tiles[8][8];
    QGraphicsRectItem* whiteOut[10];
    QGraphicsRectItem* blackOut[10];
    QLabel* toptext;
    QPushButton* exitButton;
    QPushButton* newgameButton;
    int m_blackNext;
    int m_whiteNext;
    int m_turn;
    void updateText();
};

#endif // CHESS_H
