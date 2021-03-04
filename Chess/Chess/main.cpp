#include "pawn.h"
#include "board.h"
int main() {
	Board board{};
	board.movePiece(1, 7, 1, 5, false);
	board.movePiece(1, 5, 1, 4, false);
	board.movePiece(1, 4, 1, 3, false);
	board.movePiece(1, 3, 2, 2, false);
	return 0;
}
