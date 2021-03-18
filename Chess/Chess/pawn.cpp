// Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Colour colour) : Piece(x, y, colour), m_hasMoved(false), m_hasHopped(false)
{}

int Pawn::checkMove(int x, int y) {
	if (Piece::checkMove(x, y) == 2)
		return 2;

	if (getX() == x && getY() + (int)getColour() == y) {
		return 0;
	}

	if ((getX() == x + 1 || getX() == x - 1) && getY() + (int)getColour() == y) {
		return 0;
	}

	else if (getX()== x && getY() + 2 * (int)getColour() == y && !m_hasMoved) {
		return -2;
	}

	return 1;
}

bool Pawn::hasMoved(){
	return m_hasMoved;
}