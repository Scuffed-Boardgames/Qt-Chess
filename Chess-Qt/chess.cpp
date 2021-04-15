#include "chess.h"
#include <QGridLayout>
#include <QVBoxLayout>




chess::chess(QWidget *parent) : QWidget(parent){
    m_ai = m_game->giveAi();
    m_blackNext = 0;
    m_whiteNext = 0;
    m_game = new Game;
    scene = new CustomGraphics(0,0,800,800, m_game->giveBoard());
    scene->setBoard(m_game->giveBoard());
    view = new QGraphicsView((QGraphicsScene*)scene);
    view->setVisible(false);
    makeBoard();
    makeButtons();
    m_turn = 1;
    scene->setTurn(m_turn);
    toptext = new QLabel("Which player(s) should be ai?");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(toptext, 0);
    mainLayout->addWidget(group1, 1);
    mainLayout->addWidget(group2, 1);
    mainLayout->addWidget(view, 2);
    setLayout(mainLayout);
    group1->setVisible(false);
    connects();
}

void chess::makeButtons(){
    noneButton = new QPushButton("None");
    blackButton = new QPushButton("Black");
    whiteButton = new QPushButton("White");
    bothButton = new QPushButton("Both");
    exitButton = new QPushButton("Quit game");
    newgameButton = new QPushButton("New game");
    group1 = new QGroupBox();
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(exitButton);
    layout1->addWidget(newgameButton);
    group1->setLayout(layout1);
    group1->setFixedHeight(50);

    group2 = new QGroupBox();
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(noneButton);
    layout2->addWidget(blackButton);
    layout2->addWidget(whiteButton);
    layout2->addWidget(bothButton);
    group2->setLayout(layout2);
}
void chess::makeBoard(){
    QBrush brushgrey;
    brushgrey.setColor(Qt::gray);
    brushgrey.setStyle(Qt::SolidPattern);
    QBrush brushwhite;
    brushwhite.setColor(Qt::white);
    brushwhite.setStyle(Qt::SolidPattern);
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
}
void chess::setPieces(){
    for (int i = 0; i < 8; ++i) {
        blackpieces[i]->setParentItem(tiles[i][6]);
    }
    blackpieces[8]->setParentItem(tiles[0][7]);
    blackpieces[9]->setParentItem(tiles[7][7]);
    blackpieces[10]->setParentItem(tiles[1][7]);
    blackpieces[11]->setParentItem(tiles[6][7]);
    blackpieces[12]->setParentItem(tiles[2][7]);
    blackpieces[13]->setParentItem(tiles[5][7]);
    blackpieces[14]->setParentItem(tiles[3][7]);
    blackpieces[15]->setParentItem(tiles[4][7]);
    for (int i = 0; i < 8; ++i) {
        whitepieces[i]->setParentItem(tiles[i][1]);
    }
    whitepieces[8]->setParentItem(tiles[0][0]);
    whitepieces[9]->setParentItem(tiles[7][0]);
    whitepieces[10]->setParentItem(tiles[1][0]);
    whitepieces[11]->setParentItem(tiles[6][0]);
    whitepieces[12]->setParentItem(tiles[2][0]);
    whitepieces[13]->setParentItem(tiles[5][0]);
    whitepieces[14]->setParentItem(tiles[3][0]);
    whitepieces[15]->setParentItem(tiles[4][0]);
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
    if(m_game->isAi(1 - (m_turn % 2)))
        aiMove();
}
void chess::connects(){
    Board* board = m_game->giveBoard();
    connect(getScene(), &CustomGraphics::madeMove, this, &chess::moveMade);
    connect(board, &Board::removedPiece, this, &chess::removePiece);
    connect(board, &Board::reachedVictory, this, &chess::gameEnded);
    connect(board, &Board::reachedVictory, getScene(), &CustomGraphics::setEnded);
    connect(getButton(1), SIGNAL(clicked()), this, SLOT(close()));
    connect(getButton(2), &QPushButton::clicked, this, &chess::reset);
    connect(getButton(3), &QPushButton::clicked, this, &chess::setAi);
    connect(getButton(4), &QPushButton::clicked, this, &chess::setAi);
    connect(getButton(5), &QPushButton::clicked, this, &chess::setAi);
    connect(getButton(6), &QPushButton::clicked, this, &chess::setAi);
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

QPushButton* chess::getButton(int buttonNr){
    switch (buttonNr){
    case 1:
        return exitButton;
    case 2:
        return newgameButton;
    case 3:
        return noneButton;
    case 4:
        return whiteButton;
    case 5:
        return blackButton;
    case 6:
        return bothButton;
    default:
        return NULL;

    }
}

void chess::reset(){
    m_turn = 1;
    scene->setTurn(m_turn);
    toptext->setText("Turn: 1 | Move: White");
    setPieces();
    m_game->resetBoard();
}

void chess::setAi(){
    group2->setVisible(false);
    group1->setVisible(true);
    view->setVisible(true);
    QString colour;
    if(m_turn % 2 == 0)
        colour = "Black";
    else
        colour = "White";
    QString text = QString("Turn: ") + QString::number(m_turn) + QString(" | Move: ") + colour;
    toptext->setText(text);

    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked
    QString buttonText = buttonSender->text(); // retrive the text from the button clicked
    if (buttonText == "White"){
        m_game->setAi(1);
        aiMove();
    } else if(buttonText == "Black"){
        m_game->setAi(2);
    }else if(buttonText == "Both"){
        m_game->setAi(3);
        aiMove();
    }
}

void chess::aiMove(){
    Colour colour;
    if(m_turn % 2 != 0)
        colour = Colour::white;
    else
        colour = Colour::black;
   std::vector<int> move = m_ai->playMove(colour, m_game->giveBoard());
   int x1 = move[0];
   int y1 = move[1];
   int x2 = move[2];
   int y2 = move[3];
   QList<QGraphicsItem*> child = tiles[x1][y1]->childItems();
   child[0]->setParentItem(tiles[x2][y2]);
   moveMade();
}
