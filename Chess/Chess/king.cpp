#include "king.h"
#include <cstdlib>
King::King(int x, int y, Colour colour) : Piece(x, y, colour)
{}

error King::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == error::outOfBounds)
		return error::outOfBounds;
	int x1 = getX();
	int y1 = getY();
	if (((x1 != x2) || (y1 != y2)) && abs(x1-x2) <= 1 && abs(y1 - y2) <= 1)
		return error::none;
	return error::illegalMove;
}

char King::getName() {
	return 'K';
}