#include <QApplication>
#include "chess.h"
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Game k;
    chess w(nullptr, &k);
    Board* board = k.giveBoard();
    chess::connect(w.getScene(), &CustomGraphics::madeMove, &w, &chess::moveMade);
    chess::connect(board, &Board::removedPiece, &w, &chess::removePiece);
    chess::connect(board, &Board::reachedVictory, &w, &chess::gameEnded);
    chess::connect(board, &Board::reachedVictory, w.getScene(), &CustomGraphics::setEnded);
    chess::connect(w.getButton(1), SIGNAL(clicked()), &w, SLOT(close()));
    chess::connect(w.getButton(2), &QPushButton::clicked, &w, &chess::reset);
    w.show();
    return a.exec();

}

