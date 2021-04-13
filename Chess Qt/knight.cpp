#include "knight.h"
#include <cstdlib>
Knight::Knight(int x, int y, Colour colour) : Piece(x, y, colour)
{}
error Knight::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == error::outOfBounds)
		return error::outOfBounds;
	int x1 = getX();
	int y1 = getY();
	if (((abs(x1 - x2) == 1) && (abs(y1 - y2) == 2)) || ((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1)))
		return error::none;
	return error::illegalMove;
}

char Knight::getName() {
	return 'k';
}
