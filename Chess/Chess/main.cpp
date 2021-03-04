#include "pawn.h"
#include "board.h"
#include "ai.h"

int main() {
	Board board{};
	Ai ai(true, &board);
	ai.playMove();
	board.print();
	return 0;
}
