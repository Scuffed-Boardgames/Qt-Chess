#include "queen.h"
#include <cstdlib>
Queen::Queen(int x, int y, Colour colour) : Piece(x, y, colour)
{}

error Queen::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == error::outOfBounds)
		return error::outOfBounds;
	int x1 = getX();
	int y1 = getY();
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
		return error::none;
	if (abs(x1 - x2) == abs(y1 - y2))
		return error::none;
	return error::illegalMove;
}

char Queen::getName() {
	return 'Q';
}