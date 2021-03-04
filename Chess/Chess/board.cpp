// written by Bernd Uijtdebroeks except for take pawn
#include "board.h"
#include <iostream>

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
Pawn* Board::checkPiece(int x, int y, bool isWhite) {
	if (!isWhite) { // Check for white->black
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

int Board::takePawn(int x_1, int y_1, int x_2, int y_2, bool isWhite) {
	Pawn* attacker = checkPiece(x_1, y_1, isWhite);
	Pawn* target = checkPiece(x_2, y_2, !isWhite);
	if (attacker && target) {
		int test = attacker->validTake(x_2, y_2);
		if (test > 0) {
			return test;
		}
		target->setTaken();
		return test;	
	}
	if (attacker){
		std::cout << "target does not exist! \n";
		return 4;
	}
	std::cout << "attacker does not exist! \n";
	return 3;
}