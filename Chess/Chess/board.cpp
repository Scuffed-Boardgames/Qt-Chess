// written by Bernd Uijtdebroeks except for take pawn
#include "board.h"
#include <iostream>
//returns all white pawns(Denzell Mgbokwere)
Pawn* Board::getPawnW() {
	return m_pawnW;
}

//returns all black pawns(Denzell Mgbokwere)
Pawn* Board::getPawnB() {
	return m_pawnB;
}
// Default constructor for the Board class (Bernd Uijtdebroeks)
Board::Board() {
	for (int i = 0; i < 8; ++i) {
		Pawn wPawn((i + 1), 2, true); //Fills array with pawns on line 2 for white
		m_pawnW[i] = wPawn;
		Pawn bPawn((i + 1), 7, false); //Fills array with pawns on line 7 for black
		m_pawnB[i] = bPawn;
	}
}

// Checks if pawn is in given space, returns that pawn or NULL if space is empty or out of bounds (Bernd Uijtdebroeks)
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

// checks if a move is legal and plays it (Denzell Mgbokwere)
int Board::movePiece(int x_1, int y_1, int x_2, int y_2, bool isWhite) {
	Pawn* selected = checkPiece(x_1, y_1, isWhite);
	Pawn* target = checkPiece(x_2, y_2, !isWhite);
	bool sameColour = false;
	if (!target) {
		Pawn* target = checkPiece(x_2, y_2, isWhite);
		sameColour = true;
	}

	if (!selected) {
		std::cout << "selected piece does not exist! \n";
		return 3;
	}

	if (selected && !target) {
		int test = selected->move(x_2, y_2);
		return test;
	}

	if (selected && target && !sameColour) {
		int test = selected->validTake(x_2, y_2);
		if (test > 0) {
			return test;
		}
		target->setTaken();
		return test;
	}
	std::cout << "target space is occupied! \n";
	return 1;
}