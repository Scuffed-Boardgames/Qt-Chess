#include "pawn.h"
#include "board.h"
int main() {
	Board board{};
	board.print();
	board.movePiece(1, 7, 1, 5, false);
	board.print();
	board.movePiece(1, 5, 1, 4, false);
	board.print();
	board.movePiece(1, 4, 1, 3, false);
	board.print();
	board.movePiece(1, 2, 1, 4, true);
	board.print();
	board.movePiece(1, 3, 2, 2, false);
	board.print();
	return 0;
}
