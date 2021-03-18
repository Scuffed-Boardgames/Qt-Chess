#include "queen.h"
#include <cstdlib>
Queen::Queen(int x, int y, Colour colour) : Piece(x, y, colour)
{}

int Queen::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == 2)
		return 2;
	int x1 = getX();
	int y1 = getY();
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
		return 1;
	if (abs(x1 - x2) == abs(y1 - y2))
		return 1;
	return 0;
}