#include "queen.h"

int Queen::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == 2)
		return 2;
	if ((Bishop::checkMove(x2, y2) == 1) || (Rook::checkMove(x2, y2) == 1))
		return 1;
	else
		return 0;
}