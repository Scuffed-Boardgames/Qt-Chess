// Denzell Mgbokwere
#include "pawn.h"
#include <iostream>

Pawn::Pawn(int x, int y, Colour colour) : Piece(x, y, colour), m_hasMoved(false), m_hasHopped(false)
{}

int Pawn::checkMove(int x, int y) {
	if (Piece::checkMove(x, y) == 2)
		return 2;
	int pawnX = getX();
	int pawnY = getY();
	if (pawnX  == x && pawnY + (int)getColour() == y) {
		return 0;
	}

	if ((pawnX  == x + 1 || pawnX  == x - 1) && pawnY + (int)getColour() == y) {
		return -1;
	}

	else if (pawnX == x && pawnY + 2 * (int)getColour() == y && !m_hasMoved) {
		return 0;
	}

	return 1;
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