#include "pawn.h"
#include "board.h"
int main() {
	Board board{};
	Pawn* pawn = board.checkEnemy(1, 7, true);
	return 0;
}
