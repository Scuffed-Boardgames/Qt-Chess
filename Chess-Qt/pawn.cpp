// Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Colour colour) : Piece(x, y, colour), m_hasHopped(false), m_hasMoved(false)
{}

error Pawn::checkMove(int x, int y) {
	if (Piece::checkMove(x, y) == error::outOfBounds)
		return error::outOfBounds;
	int pawnX = getX();
	int pawnY = getY();
	if (pawnX  == x && pawnY + (int)getColour() == y) {
		return error::none;
	}

	if ((pawnX  == x + 1 || pawnX  == x - 1) && pawnY + (int)getColour() == y) {
        return error::enPassent;
	}

	else if (pawnX == x && pawnY + 2 * (int)getColour() == y && !m_hasMoved) {
		return error::none;
	}

	return error::illegalMove;
}

void Pawn::setMoved() {
	m_hasMoved = true;
}

bool Pawn::hasMoved(){
	return m_hasMoved;
}

char Pawn::getName() {
	return 'p';
}
