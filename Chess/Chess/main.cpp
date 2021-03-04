#include "pawn.h"
#include "board.h"
int main() {
	Board board{};
	Pawn* pawn = board.checkPiece(1, 7, false);
	pawn->move(1, 5);
	pawn->move(1, 4);
	pawn->move(1, 3);
	board.takePawn(1, 3, 2, 2, false);
	return 0;
}
