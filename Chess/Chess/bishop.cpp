#include "bishop.h"
#include <cstdlib>
Bishop::Bishop(int x, int y, Colour colour) : Piece(x, y, colour)
{}
int Bishop::checkMove(int x2, int y2) {
	if (Piece::checkMove(x2, y2) == 2)
		return 2;
	int x1 = getX();
	int y1 = getY();
	if (abs(x1 - x2) == abs(y1 - y2))
		return 0;
	return 1;
}

char Bishop::getName() {
	return 'b';
}
