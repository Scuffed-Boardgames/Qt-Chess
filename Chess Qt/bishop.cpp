#include "bishop.h"
#include <cstdlib>
Bishop::Bishop(int x, int y, Colour colour) : Piece(x, y, colour)
{}
error Bishop::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == error::outOfBounds)
		return error::outOfBounds;
	int x1 = getX();
	int y1 = getY();
	if (abs(x1 - x2) == abs(y1 - y2))
		return error::none;
	return error::illegalMove;
}

char Bishop::getName() {
	return 'b';
}
