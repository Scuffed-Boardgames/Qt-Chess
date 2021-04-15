#include <QApplication>
#include "chess.h"
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Game k;
    Board* board = k.giveBoard();
    chess w(nullptr, board);
    chess::connect(w.getScene(), &CustomGraphics::madeMove, &w, &chess::moveMade);
    chess::connect(board, &Board::removedPiece, &w, &chess::removePiece);
    chess::connect(board, &Board::reachedVictory, &w, &chess::gameEnded);
    chess::connect(board, &Board::reachedVictory, w.getScene(), &CustomGraphics::setEnded);
    chess::connect(w.getButton(1), SIGNAL(clicked()), &w, SLOT(close()));
    w.show();
    return a.exec();

}
