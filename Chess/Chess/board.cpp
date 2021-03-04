#include "board.h"

// Default constructor for the Board class
Board::Board() {
	for (int i = 0; i < 8; ++i) {
		Pawn wPawn((i + 1), 2, true); //Fills array with pawns on line 2 for white
		m_pawnW[i] = wPawn;
		Pawn bPawn((i + 1), 7, false); //Fills array with pawns on line 7 for black
		m_pawnB[i] = bPawn;
	}
}

// Checks if enemy pawn is in given space, returns that pawn or NULL if space is empty or out of bounds
Pawn* Board::checkEnemy(int x, int y, bool isWhite) {
	if (isWhite) { // Check for white->black
		for (int i = 0; i < 8; ++i)
			if (m_pawnB[i].getX() == x && m_pawnB[i].getY() == y)
				return &m_pawnB[i];
	}
	else { // Check for black->white
		for (int i = 0; i < 8; ++i)
			if (m_pawnW[i].getX() == x && m_pawnW[i].getY() == y)
				return &m_pawnW[i];
	}
	return NULL;
}