#include <QApplication>
#include "chess.h"
#include "game.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Game k;
    Board* board = k.giveBoard();
    chess w(nullptr, k.giveBoard());
    chess::connect(w.getScene(), &CustomGraphics::madeMove, &w, &chess::moveMade);
    chess::connect(board, &Board::removedPiece, &w, &chess::removePiece);
    w.show();
    return a.exec();

}
