#include "rook.h"

int Rook::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == 2)
		return 2;
	int x1 = getX();
	int y1 = getY();
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
		return 0;
	else
		return 1;
}