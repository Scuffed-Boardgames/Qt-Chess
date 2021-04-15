#ifndef CHESS_H
#define CHESS_H

#include <QGraphicsView>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include "boardview.h"
#include "game.h"


class chess : public QWidget
{
    Q_OBJECT
public:
    explicit chess(QWidget *parent = nullptr);
    CustomGraphics* getScene();
    QPushButton* getButton(int buttonNr);
    int getTurn();
public slots:
    void moveMade();
    void removePiece(int x, int y, Colour colour);
    void gameEnded(Colour colour);
    void setAi();
    void aiMove();
private:
    std::unique_ptr<Game> m_game;
    std::shared_ptr<Ai> m_ai;
    int m_blackNext;
    int m_whiteNext;
    int m_turn;
    bool m_gameEnded;

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
    QPushButton* noneButton;
    QPushButton* blackButton;
    QPushButton* whiteButton;
    QPushButton* bothButton;
    QGroupBox* group1;
    QGroupBox* group2;

    void reset();
    void connects();
    void makeButtons();
    void setPieces();
    void makeBoard();
    void updateText();
    void setEnded();
};

#endif // CHESS_H
