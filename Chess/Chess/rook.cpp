#include "rook.h"
Rook::Rook(int x, int y, Colour colour) : Piece(x, y, colour)
{}
error Rook::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == error::outOfBounds)
		return error::outOfBounds;
	int x1 = getX();
	int y1 = getY();
	if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2))
		return error::none;
	return error::illegalMove;
}

char Rook::getName() {
	return 'R';
}